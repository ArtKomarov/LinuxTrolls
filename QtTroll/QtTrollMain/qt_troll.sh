#!/bin/bash

# Prepare qt:
# sudo apt-get install build-essential
# sudo apt-get install qtcreator
# sudo apt install qt5-default
# sudo apt-get install qt5-doc qtbase5-examples qtbase5-doc-html

path=$(dirname "$0")

# Preparations
qmake QtTrollMain.pro
make

# Run
export LD_LIBRARY_PATH=$path/../QtTrollLib/ && nohup ./qt_troll &

