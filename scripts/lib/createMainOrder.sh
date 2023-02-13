#!/bin/bash

# $n = Command line argument n.
# $1 = exStart
# $2 = exEnd

for ((i = $1; i <= $2; i++))
do
  leadingZero=''
  if (( i < 10 ))
  then
    leadingZero='0'
  fi
  folderName=$leadingZero$i
  sed -i 's/\.\///g' $folderName/order.txt 
  cat $folderName/order.txt | while read line; do echo "./$folderName/$line" >> mainOrder; done
  sed -i 's/-//g' mainOrder
  echo "./$folderName/order.txt" >> mainOrder
done
echo "./metadata.txt" >> mainOrder