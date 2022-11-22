#!/bin/sh

echo "Running pre-commit verification script"

mkdir -p build
cd build
rm -rf *
cmake -Wno-dev ../ > log-latest
make

if [ $? -ne 0 ]; then
    echo "Abort - Program doesn't compile, please fix it"
    exit 1
fi