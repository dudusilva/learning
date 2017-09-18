#!/bin/bash

containAllRots() {
    count=0
    word="$1"
    len=${#word}

    for (( i=0; i<${len}; i++ ))
    do
        ini=$( echo $word | cut -c 2- )
        end=$( echo $word | cut -c -1 )
        word=$ini$end

        if [[ "$2" == *"$word"* ]]
        then
            count=$(( $count+1 ))
        fi
    done

    if [ $count -eq $len ]
    then
        echo true
    else
        echo false
    fi
}

containAllRots $1 "$2"

