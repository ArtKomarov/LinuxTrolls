#!/bin/bash

path=$(dirname "$0")

# Preparations
if [ "$1" == "--include-preparations" ]
then
    g++ -c shell_troll.cpp -Wall -Wextra -fPIC
    g++ -shared -o libshell_troll.so shell_troll.o
fi

# Compile
g++ -Wall -Wextra $path/main.cpp -o main.out -L $path -lshell_troll

# Run
export LD_LIBRARY_PATH=$path && ./main.out

