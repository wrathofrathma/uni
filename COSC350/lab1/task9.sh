#!/bin/bash

echo "Please enter a directory name: "
read dir

if [ ! -d $dir ]; then
	echo "Directory doesn't exist!"
	exit 1
fi

for i in {1..3}
do
	echo "Please enter a filename that exists within directory $dir/"
	read fname
	
	fpath=$dir/$fname
	echo "Searching for file: $fpath"

	if [ ! -e $fpath ]; then
		echo "File not found! $i attempts left."
	elif [ ! -r $fpath ]; then
		echo "File not readable! $i attempts left."
	else
		echo "File found! Name a word to find in the file: " 
		read word

		if grep -q $word $fpath ; then
			echo "$word FOUND!"
			exit 0
		else
			echo "$word NOT FOUND"
			exit 4
		fi
	fi
done
exit 2 # Should only ever reach this if we don't exit within the loop. which means file wasn't found

