#!/bin/bash

wallpaper() {
    names=(zero one two three four five six seven eight nine ten\
           eleven twelve thirteen fourteen fifteen sixteen\
           seventeen eighteen nineteen twenty)

    test_lwh=$( echo "$1 * $2 * $3 == 0.0" | bc -l )

    if [ $test_lwh == 1 ] 
    then
        rolls=0
    else
        area=$( echo "(($1 * $3) + ($2 * $3)) * 2.30" | bc -l )
        rolls=$( echo "a=$area; b=5.2; if (a%b) a/b+1 else a/b" | bc )
    fi

    echo ${names[$rolls]}
}

wallpaper $1 $2 $3
