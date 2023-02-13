#!/bin/bash

# $n = Command line argument n.
# $0 = script name
# $1 = set number
# $2 = exStart
# $3 = exEnd


if [[ -z "$1" ]]; then
    echo "Must provide arg 1 (set num) in environment" 1>&2
    exit 1
fi

if [[ -z "$2" ]]; then
    echo "Must provide arg 2 (ex start) in environment" 1>&2
    exit 1
fi

if [[ -z "$3" ]]; then
    echo "Must provide arg 3 (ex end) in environment" 1>&2
    exit 1
fi

cd set$1

echo "Making order.txt files"

for ((i = $2; i <= $3; i++))
do
  leadingZero=''
  if (( i < 10 ))
  then
    leadingZero='0'
  fi
  folderName=$leadingZero$i
  
  echo "Making order.txt for $folderName/"
  cd $i
  find -type f -not -path "./.idea/*" -not -path "./cmake-build-debug/*" \
  -not -path "./order.txt" -not -path "./CMakeLists.txt" \
  -not -path "./tests/*" \
  > order.txt
  cd ..
done