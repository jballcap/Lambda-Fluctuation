#!/bin/bash
if [ -z "$2" ]
        then
                echo "You need an argument of the form (commit hash) (number of FemtoDsts)"
                exit 1
        fi

if [ "$3" ]
        then
                echo "You need an argument of the form (commit hash) (number of FemtoDsts)"
                exit 1
        fi


chmod +x AnalyzeFemtoDst.bin
make
echo ""
read -p "Press enter if this compiled; otherwise CTRL + c to exit"
echo "Okay, starting now"

./AnalyzeFemtoDst.bin $1 $2
