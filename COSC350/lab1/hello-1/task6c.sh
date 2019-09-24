#!/bin/bash

echo -n  "Please input a number between 5 to 9: "
read input
if [ $input -lt 5 ]; then
    echo "Try again with a number between 5 to 9"
    exit -1
fi

if [ $input -gt 9 ]; then
    echo "Try again with a number between 5 to 9"
    exit -1
fi



for i in $(seq 1 $input)
do
    let space=$input-$i
    for j in $(seq 1 $space)
    do
        echo -n " "
    done
    for j in $(seq 1 $i)
    do
        echo -n "$i "
    done
    echo ""
done

