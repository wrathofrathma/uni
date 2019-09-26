#!/bin/bash

for i in {1..5}
do
	for ((j=1; j<=$i; j++))
	do
		echo -n "*"
	done
	echo ""
done

for i in {4..1}
do
	for ((j=1; j<=$i; j++))
	do
		echo -n "*"
	done
	echo ""
done
exit 0
