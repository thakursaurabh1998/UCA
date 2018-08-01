#!/bin/bash

read -p "Enter a number: " a

case $a in
    5) echo "5" ;;
    10) echo "10" ;;
    *) echo "No option" ;;
esac
