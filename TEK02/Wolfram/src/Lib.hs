--
-- EPITECH PROJECT, 2022
-- wolfram
-- File description:
-- Lib
--

module Lib (
    wolfram
) where

import System.Environment
import System.Exit
import System.IO
import Data.Char

usage :: IO ()
usage = putStrLn "Usage :\n" >>
 putStrLn "Flags: \t--rule\t\t30, 90, 110 /!\\ required" >>
 putStrLn "\t--lines\t\t[int] >= 0" >>
 putStrLn "\t--move\t\t[int]" >>
 putStrLn "\t--window\t[int] >= 0" >>
 putStrLn "\t--start\t\t[int] >= 0" >>
 exitWith (ExitFailure 84)

firstGen :: Int -> Int -> [Char] -> [Char]
firstGen i windowSize output
    | i == (windowSize `div` 2) = firstGen (i + 1) windowSize (output ++ "*")
    | i <= (250 + windowSize) = firstGen (i + 1) windowSize (output ++ " ")
    | otherwise = output

readInt :: [Char] -> Int
readInt [] = 0
readInt (a:as) = read (a:as) :: Int


checkLength :: [Char] -> [Char]
checkLength tab
  | length tab < 8 = checkLength (" " ++ tab)
  | otherwise = tab

ruleConversion :: Int -> [Char] -> [Char]
ruleConversion 0 tab = checkLength tab
ruleConversion rule tab
    | rule `mod` 2 == 1 = ruleConversion (rule `div` 2) ("*" ++ tab)
    | otherwise = ruleConversion (rule `div` 2) (" " ++ tab)

isSingleRule :: [[Char]] -> [Char] -> Int -> Int -> IO ()
isSingleRule args rule i nbrRule
    | args !! i == rule && nbrRule == 1 = usage
    | (args !! i == rule) && isInt (args !! (i + 1)) = isSingleRule args
     rule (i + 1) 1
    | (args !! i == rule) && not (isInt (args !! (i + 1))) = usage
    | (i + 1) == length args && (args !! i == rule) = usage
    | (i + 1) == length args = return ()
    | otherwise = isSingleRule args rule (i + 1) nbrRule

isSinglePosRule :: [[Char]] -> [Char] -> Int -> Int -> IO ()
isSinglePosRule args rule i nbrRule
    | args !! i == rule && nbrRule == 1 = usage
    | (args !! i == rule) && isPosInt (args !! (i + 1)) = isSinglePosRule args
     rule (i + 1) 1
    | (args !! i == rule) && not (isPosInt (args !! (i + 1))) = usage
    | (i + 1) == length args && (args !! i == rule) = usage
    | (i + 1) == length args = return ()
    | otherwise = isSinglePosRule args rule (i + 1) nbrRule

getLines :: [[Char]] -> Int -> Int
getLines args i
    | args !! i == "--lines" = read (args !! (i + 1)) :: Int
    | (i + 1) == length args = -1
    | otherwise = getLines args (i + 1)

getStart :: [[Char]] -> Int -> Int
getStart args i
    | args !! i == "--start" = read (args !! (i + 1)) :: Int
    | (i + 1) == length args = 0
    | otherwise = getStart args (i + 1)

getWindow :: [[Char]] -> Int -> Int
getWindow args i
    | args !! i == "--window" = read (args !! (i + 1)) :: Int
    | (i + 1) == length args = 80
    | otherwise = getWindow args (i + 1)

getMove :: [[Char]] -> Int -> Int
getMove args i
    | args !! i == "--move" = read (args !! (i + 1)) :: Int
    | (i + 1) == length args = 0
    | otherwise = getMove args (i + 1)

raiseLastGen :: [Char] -> Int -> [Char]
raiseLastGen lastGen elem
    | elem <= length lastGen = lastGen ++ " "
    | otherwise = lastGen

applyRule :: Int -> Int -> [Char] -> [Char] -> Int -> [Char] -> Int -> [Char]
applyRule start i l nextGen 0 rule windowSize = newLine start (i + 1) l
 (nextGen ++ " ") 1 rule windowSize
applyRule start i l nextGen e rule windowSize
    | l !! e == '*' && l !! (e + 1) == '*' && l !! (e - 1) == '*' = newLine
     start (i + 1) l (nextGen ++ [rule !! 0]) (e + 1) rule windowSize
    | l !! e == '*' && l !! (e + 1) == ' ' && l !! (e - 1) == '*' = newLine
     start (i + 1) l (nextGen ++ [rule !! 1]) (e + 1) rule windowSize
    | l !! e == ' ' && l !! (e + 1) == '*' && l !! (e - 1) == '*' = newLine
     start (i + 1) l (nextGen ++ [rule !! 2]) (e + 1) rule windowSize
    | otherwise = applyRuleNext start i l nextGen e rule windowSize

applyRuleNext :: Int -> Int -> [Char] -> [Char] -> Int -> [Char] -> Int ->
 [Char]
applyRuleNext start i l nextGen e rule windowSize
    | l !! e == ' ' && l !! (e + 1) == ' ' && l !! (e - 1) == '*' = newLine
     start (i + 1) l (nextGen ++ [rule !! 3]) (e + 1) rule windowSize
    | l !! e == '*' && l !! (e + 1) == '*' && l !! (e - 1) == ' ' = newLine
     start (i + 1) l (nextGen ++ [rule !! 4]) (e + 1) rule windowSize
    | l !! e == '*' && l !! (e + 1) == ' ' && l !! (e - 1) == ' ' = newLine
     start (i + 1) l (nextGen ++ [rule !! 5]) (e + 1) rule windowSize
    | otherwise = applyRuleNextNext start i l nextGen e rule windowSize

applyRuleNextNext :: Int -> Int -> [Char] -> [Char] -> Int -> [Char] -> Int ->
 [Char]
applyRuleNextNext start i l nextGen e rule windowSize
    | l !! e == ' ' && l !! (e + 1) == '*' && l !! (e - 1) == ' ' = newLine
     start (i + 1) l (nextGen ++ [rule !! 6]) (e + 1) rule windowSize
    | l !! e == ' ' && l !! (e + 1) == ' ' && l !! (e - 1) == ' ' = newLine
     start (i + 1) l (nextGen ++ [rule !! 7]) (e + 1) rule windowSize
    | otherwise = newLine start (i + 1) l (nextGen ++ "*") (e + 1) rule
     windowSize

newLine :: Int -> Int -> [Char] -> [Char] -> Int -> [Char] -> Int -> [Char]
newLine start i lastGen nextGen elem rule windowSize
    | i < (250 + windowSize) = applyRule start i lastGen nextGen elem rule
     windowSize
    | i == (250 + windowSize) = newLine start (i + 1) lastGen (nextGen ++ " ")
     (elem + 1) rule windowSize
    | otherwise = nextGen

wolframLoop :: [Int] -> [Char] -> [Char] -> Int -> Int -> IO ()
wolframLoop [lines, start, windowSize, move] lastGen rule nBefStart i
    | nBefStart >= (start - 1) = putStrLn (take windowSize (drop (250 - move)
     (newLine start (-250) lastGen [] 0 rule windowSize))) >>
     wolframLoopCheck [lines, start, windowSize, move] (i + 1) (nBefStart + 1)
     (newLine start (-250) lastGen [] 0 rule windowSize) rule
    | otherwise = wolframLoopCheck [lines, start, windowSize, move] (i + 1)
     (nBefStart + 1) (newLine start (-250) lastGen [] 0 rule windowSize) rule
wolframLoop _ _ _ _ _ = return ()


wolframLoopCheck :: [Int] -> Int -> Int -> [Char] -> [Char] -> IO ()
wolframLoopCheck [-1, start, windowSize, move] i  nBefStart lastGen rule =
 wolframLoop [-1, start, windowSize, move] lastGen rule nBefStart 0
wolframLoopCheck [lines, start, windowSize, move] i nBefStart lastGen rule
    | i < ((lines - 1) + start) = wolframLoop [lines, start, windowSize, move]
     lastGen rule nBefStart i
    | otherwise = return ()
wolframLoopCheck _ _ _ _ _ = return ()

initWolfram :: [[Char]] -> [Int] -> Int -> IO ()
initWolfram args [lines, start, windowSize, move] i
    | i >= length args = usage
    | args !! i == "--rule" && isInt (args !! (i + 1)) && start == 0 = putStrLn
     (take windowSize (drop (250 - move) (firstGen (-250) windowSize []))) >>
     wolframLoopCheck [lines, start, windowSize, move] 0 0 (firstGen (-250)
      windowSize []) (ruleConversion (readInt (args !! (i + 1))) "")
    | args !! i == "--rule" && isInt (args !! (i + 1)) && start /= 0 =
     wolframLoopCheck [lines, start, windowSize, move] 0 0 (firstGen (-250)
      windowSize []) (ruleConversion (readInt (args !! (i + 1))) "")
    | otherwise = initWolfram args [lines, start, windowSize, move] (i + 1)
initWolfram _ _ _ = return ();

wolfram :: [String] -> IO ()
wolfram [] = exitWith (ExitFailure 84)
wolfram args = argsManagement 0 (drop 1 args) >> isSinglePosRule args "--rule"
 0 0 >> isSinglePosRule args "--start" 0 0 >> isSinglePosRule args "--window"
 0 0 >> isSingleRule args "--move" 0 0 >> isSinglePosRule args "--lines" 0 0
 >> initWolfram args [getLines args 0, getStart args 0, getWindow args 0,
 getMove args 0] 0

hasRule :: [String] -> IO ()
hasRule a = return ()

isInt :: String -> Bool
isInt a = case reads a :: [(Integer, String)] of
    [(_, "")] -> True
    _ -> False

isPosInt :: String -> Bool
isPosInt [] = True
isPosInt (a:as)
    | isDigit a = isPosInt as
    | otherwise = False

argsManagement :: Int -> [[Char]] -> IO ()
argsManagement i args
    | null args = usage
    | args !! i == "--help" = usage
    | args !! i == "-h" = usage
    | ((args !! i) /= "--start") && ((args !! i) /= "--window") &&
     ((args !! i) /= "--move") && ((args !! i) /= "--lines") &&
     ((args !! i) /= "--rule") && not (isInt (args !! i)) = usage
    | (i + 1) == length args = return ()
    | otherwise = argsManagement (i + 1) args

