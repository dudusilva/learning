#!/bin/bash

isPrime() {
    prime=$1

    if [ "$prime" -le 1 ]
    then
        echo false
    elif [ "$prime" -le 3 ]
    then
        echo true
    elif (( $prime % 2 == 0 )) || (( $prime % 3 == 0 ))
    then
       echo false
    else 
        i=5
        sqr=$(( $i * $i ))
        ret=true

        while [ "$sqr" -le "$prime" ]
        do
            if (( $prime % $i == 0 )) ||\
               (( $prime % ($i+2) == 0))
            then
                ret=false
                break
            fi

            i=$(( $i + 6 ))
            sqr=$(( $i * $i ))
        done

        echo "$ret"
    fi
}

backwardsPrime() {
    for ((i=$1;i<=$2;i++)); do
        test=$( isPrime $i )

        if [ "$test" = true ] 
        then
            num=$( echo "$i" | rev | bc )

            if [ "$num" -ne "$i" ]
            then
                test=$( isPrime $num )

                if [ "$test" = true ]
                then
                    res=$( echo "$res $i" )
                fi
            fi
        fi
    done

   echo "$res" | cut -c2-
}

backwardsPrime $1 $2

