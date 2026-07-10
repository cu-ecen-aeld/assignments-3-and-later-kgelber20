#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Incorrect number of arguments "
    exit 1
fi

mkdir -p "$(dirname "$1")"
touch "$1"

if [ "$?" -ne 0 ]; then
    echo "ERROR: unable to create file"
    exit 1
fi

echo $2 > $1

exit 0