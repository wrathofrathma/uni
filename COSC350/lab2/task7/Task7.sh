#!/bin/bash

function wfact {
	num=1
	i=1
	while [ $i -le $1 ]
	do
		((num*=i))
		((i++))
	done
	echo $num
}

function fact {
	num=1
	for ((i=1; i<=$1; i++))
	do
		((num*=i))
	done	
	echo $num
}

fact $1
wfact $1
