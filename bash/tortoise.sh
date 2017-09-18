#!/bin/bash

race() {
    if [ $2 -lt $1 ]
    then
        hour=-1
        min=-1
        seg=-1
    else
        vrel=$(( $2 - $1 ))
        time=$( echo "($3 * 3600) / $vrel" | bc )
        hour=$( echo "$time / 3600" | bc )
        time=$( echo "$time - 3600 * $hour" | bc )
        min=$( echo "$time / 60" | bc )
        seg=$( echo "$time - 60 * $min" | bc )
    fi

    echo "$hour $min $seg"
}

race $1 $2 $3
