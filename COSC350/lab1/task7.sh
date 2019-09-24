#!/bin/bash

if [ $# -ne 1 ];
then
	echo "Please input a commandline integer argument"
	exit -1
fi
total=1
counter=$1
while [ $counter -gt 1 ]; 
do
	let total=$total*$counter
	((counter--))
done
echo $total
