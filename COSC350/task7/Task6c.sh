#!/bin/bash

echo "Input a number between 5 and 9"
read num

if [ $num -le 9 -a $num -ge 5 ]; then
	echo "Valid number"	# lol
else
	echo "Invalid number. Please enter a number between 5-9"
	exit 1
fi

# I noticed the middle of the tree is exactly n spaces over, where n is equal to the input number

# Line number
for ((i=1; i<=num; i++))
do
	# calc the spacing on the left
	((space=num-i))
	for((j=1; j<=space; j++))
	do
		echo -n " "
	done
	# Print the numbers
	for((j=1; j<=i; j++))
	do
		echo -n "$i "
	done
	echo " "
done
