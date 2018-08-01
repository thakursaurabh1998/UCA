#!/bin/bash

read -p "Enter A: " a
read -p "Enter B: " b
temp=$a
a=$b
b=$temp

echo -e "A: $a\nB: $b"
