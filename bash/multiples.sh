#!/bin/bash

for ((i=1;i<=$3;i++)); do
    mod1=$(( $i % $1 ))
    mod2=$(( $i % $2 ))

    if [ ${mod1} -eq 0 ] && [ ${mod2} -eq 0 ];
    then
        echo $i
    fi
done

