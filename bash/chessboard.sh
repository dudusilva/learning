#!/bin/bash

game() {
    sum=$( echo "($1 * ($1 - 1))/2" | bc )
    
    if !(( $1 % 2 ))
    then
        diag=$(( $1 / 2 ))
        num=$(( $diag + $sum ))
        echo "$num"
    else
        diag=$(( $1 ))
        num=$(( $diag + 2 * $sum ))
        echo "$num, 2"
    fi
}

game $1
