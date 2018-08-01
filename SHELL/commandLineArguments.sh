#!/bin/bash

if [ $# -ne 1 ]
then
    echo "enter argument(filename)"
else
    test -e $1 && echo "yes" || echo "no"
fi
