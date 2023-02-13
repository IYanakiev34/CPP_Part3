#!/bin/bash

# arguments
# $1 = set num
# $2 = array of exercises to remove. e.g: 1,2,3

if [ "$2" == "none" ]
  then
    echo "Nothing to remove."
    exit 0
fi

IFS=',' read -r -a arr <<< $2  

for i in ${arr[@]}; do
  leadingZero=''
  if (( i < 10 ))
  then
    leadingZero='0'
  fi
  folderName=$leadingZero$i
  
  echo "Removing exercise $folderName"
  zip --delete zips/set$1.zip "$folderName/*"
done