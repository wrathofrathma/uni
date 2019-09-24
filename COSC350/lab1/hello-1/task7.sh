#!/bin/bash

let total=1
let counter=$1
while [ $counter -gt 1 ]; 
do
    let total=$total*$counter
    ((counter--))
done
echo $total
