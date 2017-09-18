#!/bin/bash

original=$( echo "$1" | awk '{ print length }' )
modified=$( echo "$1" | tr -d "aeiouAEIOU" \
            | awk '{ print length }' )
echo $(( $original - $modified ))

