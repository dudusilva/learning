#!/bin/bash
echo $1 | sed -e 'y/AT/TA/' | sed -e 'y/CG/GC/'

