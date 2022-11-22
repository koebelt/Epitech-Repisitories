--
-- EPITECH PROJECT, 2022
-- B-FUN-400-STG-4-1-compressor-ethan.husser
-- File description:
-- Lib
--

module Lib
    (
        imageCompressor,
        printUsage
    ) where

import Data.Char
import Text.Read
import System.Environment ()
import System.Exit ( ExitCode(ExitFailure), exitWith )
import System.IO
import System.IO.Unsafe
import System.Random (getStdRandom, randomR)

printError :: String -> IO ()
printError error = putStrLn error >> exitWith (ExitFailure 84)

checkInt :: [Char] -> Bool
checkInt [] = True
checkInt (x:xs)
    | isDigit x == True = checkInt xs
    | otherwise = False

preCheckContent :: String -> IO [String]
preCheckContent [] = exitWith (ExitFailure 84)
preCheckContent content
    | checkContent (lines content) == False = exitWith (ExitFailure 84)
    | otherwise = return (lines content)

openFileAsList :: String -> IO [String]
openFileAsList path = do
    content <- readFile path
    preCheckContent content

checkContent :: [String] -> Bool
checkContent [] = True
checkContent (x:xs)
    | checkContentFile ( "(" ++ (replaceSpaces x) ++ ")") == False = False
    | otherwise = checkContent xs

checkContentFile :: String -> Bool
checkContentFile str
    | (readMaybe str :: Maybe ((Int, Int), (Int, Int, Int))) == Nothing = False
    | otherwise = True

replaceSpaces :: String -> String
replaceSpaces [] = []
replaceSpaces (' ' : xs) = ',':replaceSpaces xs
replaceSpaces (x : xs) = x:replaceSpaces xs

interpretFile :: [String] -> [((Int, Int), (Int, Int, Int))]
interpretFile [] = []
interpretFile (a : as) = ((toInt (getWordAt a 0), toInt (getWordAt a 1)),
 (toInt (getWordAt a 2), toInt (getWordAt a 3), toInt (getWordAt a 4))) :
 interpretFile as

getWordAt :: String -> Int -> String
getWordAt str n = (split ',' (split ' ' (removeChar ')' (removeChar '(' str))
 !! 0) ++ split ',' (split ' ' (removeChar ')' (removeChar '(' str)) !! 1))
 !! n

toInt :: String -> Int
toInt str = read str :: Int

split :: Char -> String -> [String]
split _ "" = []
split c s = firstWord : split c rest
    where firstWord = takeWhile (/=c) s
          rest = drop (length firstWord + 1) s

printColor :: (Int, Int, Int) -> IO ()
printColor (c, d, e) = putStr "(" >> putStr (show c) >> putStr ","
 >> putStr (show d) >> putStr "," >> putStr (show e) >> putStrLn ")"

printPoint :: [((Int, Int), (Int, Int, Int))] -> IO ()
printPoint [] = return ()
printPoint (((a, b), (c, d, e)) : as) = putStr "(" >> putStr (show a) >>
 putStr "," >> putStr (show b) >> putStr ") " >> printColor (c, d, e) >>
 printPoint as

removeChar :: Char -> String -> String
removeChar _ [] = []
removeChar ch (c:cs)
    | c == ch   = removeChar ch cs
    | otherwise = c:removeChar ch cs

getRandomInt :: Int -> Int
getRandomInt max = unsafePerformIO (getStdRandom (randomR (0, max -  1)))

isSafeRandom :: (Int, Int, Int) -> [(Int, Int, Int)] -> Bool
isSafeRandom _ [] = True
isSafeRandom (r, g, b) ((f, v, n):as)
    | r == f  && g == v  && b == n = False
    | otherwise = isSafeRandom (r, g, b) as

getColor :: ((Int, Int), (Int, Int, Int)) -> (Int, Int, Int)
getColor ((a, b), (c, d, e)) = (c, d, e)

checkRandomInt :: Int -> [((Int, Int), (Int, Int, Int))] ->
    [(Int, Int, Int)] -> (Int, Int, Int)
checkRandomInt ran a n
    | isSafeRandom (getColor (a !! ran)) n == True = (getColor (a !! ran))
    | otherwise = (getSafeRandom2 a n)

getSafeRandom2 :: [((Int, Int), (Int, Int, Int))] ->
    [(Int, Int, Int)] -> (Int, Int, Int)
getSafeRandom2 a n = (checkRandomInt (getRandomInt (length a)) a n)

getSafeRandom :: [((Int, Int), (Int, Int, Int))] ->
    [(Int, Int, Int)] -> [(Int, Int, Int)]
getSafeRandom a n = (checkRandomInt (getRandomInt (length a)) a n) : n

chooseRandomColors :: [((Int, Int), (Int, Int, Int))] ->
    Int -> [(Int, Int, Int)]
chooseRandomColors _ 0 = []
chooseRandomColors (((a, b), (c, d, e)) : as) n = getSafeRandom
    (((a, b), (c, d, e)) : as)
    (chooseRandomColors (((a, b), (c, d, e)) : as) (n - 1))
chooseRandomColors _ _ = []

square :: Int -> Int
square x = x * x

calculateDistance :: (Int, Int, Int) -> (Int, Int, Int) -> Float
calculateDistance (r, g, b) (r1, g1, b1) = sqrt
    (fromIntegral (square (r - r1) + square (b - b1) + square (g - g1)))

getClusterIndex :: (Int, Int, Int) -> [(Int, Int, Int)] -> Int -> Int
getClusterIndex ref [] i = i
getClusterIndex ref (x:xs) i
    | calculateDistance ref x == 0 = i
    | otherwise = getClusterIndex ref xs (i + 1)

getClothestCluster :: ((Int, Int), (Int, Int, Int)) -> [(Int, Int, Int)] ->
    [(Int, Int, Int)] -> (Int, Int, Int) -> Int
getClothestCluster _ [] ref clothestCluster = getClusterIndex
    clothestCluster ref 0
getClothestCluster ((x, y), (r, g, b)) (a : as) ref clothestCluster
    | calculateDistance (r, g, b) a < calculateDistance (r, g, b)
        clothestCluster = getClothestCluster ((x, y), (r, g, b)) as ref a
    | otherwise = getClothestCluster ((x, y), (r, g, b)) as ref clothestCluster

assignCluster :: [((Int, Int), (Int, Int, Int))] -> [(Int, Int, Int)] ->
    Int -> [((Int, Int), (Int, Int, Int))]
assignCluster [] ref i = []
assignCluster (((x, y), (r, g, b)) : as) ref i
    | getClothestCluster ((x, y), (r, g, b)) ref ref (1000, 1000, 1000) == i =
        ((x, y), (r, g, b)):assignCluster as ref i
    | otherwise = assignCluster as ref i

createClusters :: [((Int, Int), (Int, Int, Int))] -> [(Int, Int, Int)] ->
    Int -> [[((Int, Int), (Int, Int, Int))]]
createClusters [] _ i = []
createClusters list ref i
    | i == length ref = []
    | otherwise = assignCluster list ref i : createClusters list ref (i + 1)

addClusterColors :: [((Int, Int), (Int, Int, Int))] -> (Int, Int, Int) ->
    (Int, Int, Int)
addClusterColors (((x, y), (r, g, b)) : as) (r1, g1, b1) =
    addClusterColors as (r + r1, g + g1, b + b1)
addClusterColors [] ref = ref

calcClusterMean :: [((Int, Int), (Int, Int, Int))] -> (Int, Int, Int)
calcClusterMean cluster = ((trupleNth (addClusterColors cluster (0, 0, 0)) 0)
    `div` length cluster, (trupleNth (addClusterColors cluster (0, 0, 0)) 1)
    `div` length cluster, (trupleNth (addClusterColors cluster (0, 0, 0)) 2)
    `div` length cluster)

trupleNth :: (Int, Int, Int) -> Int -> Int
trupleNth (a, b, c) 0 = a
trupleNth (a, b, c) 1 = b
trupleNth (a, b, c) _ = c

adjustClusterReference :: [[((Int, Int), (Int, Int, Int))]] ->
    [(Int, Int, Int)]
adjustClusterReference [] = []
adjustClusterReference (x : xs) = calcClusterMean x : adjustClusterReference xs

isConvergenceLimitAttained :: Float -> [(Int, Int, Int)] ->
    [(Int, Int, Int)] -> Bool
isConvergenceLimitAttained convergence [] [] = True
isConvergenceLimitAttained convergence (a : as) (x : xs)
    | convergence > calculateDistance a x = isConvergenceLimitAttained
        convergence as xs
    | otherwise = False
isConvergenceLimitAttained convergence _ _ = True

clustersLength :: [[((Int, Int), (Int, Int, Int))]] -> Int
clustersLength [] = 0
clustersLength (x : xs) = clustersLength xs + 1

printClusters :: [[((Int, Int), (Int, Int, Int))]] -> [(Int, Int, Int)] ->
    IO ()
printClusters [] [] = return ()
printClusters (x:xs) (a:as) = putStrLn "--" >>
    printColor a >>
    putStrLn "-" >>
    printPoint x >>
    printClusters xs as
printClusters _ _ = return ()

loop :: [((Int, Int), (Int, Int, Int))] -> [[((Int, Int), (Int, Int, Int))]] ->
    [(Int, Int, Int)] -> [(Int, Int, Int)] -> Float -> IO ()
loop list clusters [] ref convergence = callLoop list clusters ref
    (adjustClusterReference clusters) convergence
loop list clusters oldref ref convergence
    | not (isConvergenceLimitAttained convergence oldref ref) = callLoop list
        clusters ref (adjustClusterReference clusters) convergence
    | otherwise = printClusters clusters ref


callLoop :: [((Int, Int), (Int, Int, Int))] ->
    [[((Int, Int), (Int, Int, Int))]] -> [(Int, Int, Int)] ->
    [(Int, Int, Int)] -> Float -> IO ()
callLoop list clusters oldref ref convergence = loop list
    (createClusters list ref 0) oldref ref convergence

compress :: [((Int, Int), (Int, Int, Int))] -> Int -> Float -> IO ()
compress [] _ _ = return ()
compress (((a, b), (c, d, e)) : as) nColors convergence = callLoop
    (((a, b), (c, d, e)) : as) [] [] (chooseRandomColors
        (((a, b), (c, d, e)) : as) nColors) convergence

imageCompressor :: [String] -> IO ()
imageCompressor [] = printUsage
imageCompressor args = do
    argsManagement args
    file <- openFileAsList (args !! 5)
    compress (interpretFile file) (getArgNb args 1) (getArgNbF args 3)

getArgNb :: [String] -> Int -> Int
getArgNb args i = read (args !! i) :: Int

getArgNbF :: [String] -> Int -> Float
getArgNbF args i = read (args !! i) :: Float

argsManagement :: [String] -> IO ()
argsManagement args
    | length args /= 6 = printUsage
    | args !! 0 /= "-n" = printUsage
    | args !! 2 /= "-l" = printUsage
    | args !! 4 /= "-f" = printUsage
argsManagement _ = return ()

printUsage :: IO ()
printUsage = putStrLn "USAGE: ./imageCompressor -n N -l L -f F" >>
 putStrLn "\n\tN\tnumber of colors in the final image" >>
 putStrLn "\tL\tconvergence limit" >>
 putStrLn "\tF\tpath to the file containing the colors of the pixels" >>
 exitWith (ExitFailure 84)