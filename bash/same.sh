#!/bin/bash

comp() {
    read -a A <<< "$1"
    equal=true

    for i in ${A[*]}
    do
        ii=$(( $i*$i ))
        multA=$( echo "$1" | grep -w -o -- "$i" | wc -l )
        multB=$( echo "$2" | grep -w -o "$ii" | wc -l )

        if [ "$multA" -ne "$multB" ]
        then
            equal=false
        fi
    done

    echo $equal
}

comp "$1" "$2"

