#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Please enter exactly one integer argument"
    exit -1
fi

input=$1

sum=0
while [ $input -gt 0 ];
do
    let mod=$input%10
    let input=$input/10
    let sum=$sum+$mod
done

echo "The total sum of the digits are: $sum"
