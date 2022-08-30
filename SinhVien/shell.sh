#!/bin/sh

TIMENOW=$(date +"%A %d %B %r")
echo $TIMENOW
cat QLSV.txt

sed -i 's/Truc 2 4 6/Truc 2 4/g' QLSV.txt
sed -i 's/Truc 3 5 7/Truc 3 5/g' QLSV.txt
echo 'Sau khi thay doi'
cat QLSV.txt

TIMENOW=$(date +"%A %d %B %r")
echo $TIMENOW