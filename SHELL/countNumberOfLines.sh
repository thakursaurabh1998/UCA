#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Enter filename as argument" 

else

filename=$1

lines=$(wc -l $filename | awk -F ' ' '{print $1}')

content=$(cat $filename)

count=0

echo "Number of lines in file $filename: $lines"

fi
