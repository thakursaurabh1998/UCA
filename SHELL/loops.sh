#!/bin/bash

sum=0
for j in 1 2 3 4 5 6
do
    sum=$((sum+j))
done
echo "The sum is $sum"

sum=0

# C syntax of for loop
for((j=1;j<=6;j++))
do
    sum=$((sum+j))
done
echo "Sum: $sum"

for j in One Two Three
do
    echo $j
done

for j in {1..10}
do
    echo $j
done

for j in {1..10..2}
do
    echo $j
done
