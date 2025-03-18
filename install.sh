#!/bin/bash
echo "Compiling ..."
g++ -o grep+ main.cpp fi.cpp ut.cpp
if [ $? -eq 0 ]; then
    sudo mv grep+ /usr/bin/
    if [ $? -eq 0 ]; then
        echo "Installation successful! You can now run 'grep+'."
    else
        echo "Compilation failed."
    fi
else
    echo "Compilation failed."
fi
