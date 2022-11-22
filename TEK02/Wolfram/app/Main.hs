--
-- EPITECH PROJECT, 2022
-- wolfram
-- File description:
-- Main
--

module Main where

import System.Environment
import System.Exit
import Lib (wolfram)

main :: IO ()
main = do
    args <- getArgs
    wolfram args

