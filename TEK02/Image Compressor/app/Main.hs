module Main where

import Lib
import System.Environment
import System.Exit
import Data.Char
import System.IO

usage :: [String] -> IO ()
usage [] = return ()
usage ("-h" : as) = printUsage
usage (a:as) = usage as

main :: IO ()
main = do
    args <- getArgs
    usage args
    imageCompressor args
