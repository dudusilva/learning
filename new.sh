#!/bin/bash

last=$( ls -d [0-9]* | sort | tail -1 )
num=$( echo $last+1 | bc )
num=$( printf "%03d\n" $num )

mkdir $num
cp bas/Makefile $num
sed -i -e 's/NAME/'"$1"'/g' $num/Makefile
touch ${num}/main.c
touch ${num}/${1}.c

alias go="cd $num && vim main.c ${1}.c -c \"tab all\""

echo "project $1 created on /$num \"go\" to start"

