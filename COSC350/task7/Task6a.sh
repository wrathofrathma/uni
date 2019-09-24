#!/bin/bash

for var in {1..5}
do
	vv=1;
	while [  $vv -le  $var ]
	do
		echo -n $var
		((vv++))
	done
	echo ""
done
exit 0
