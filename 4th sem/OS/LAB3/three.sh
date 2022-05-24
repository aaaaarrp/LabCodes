#Write a Shell script to find whether the file has execute permission or not (without using test command).

#!/bin/bash
echo -n "Enter file name : "
read file

[ "`ls -l ${filename} | awk '{printf $1}' | grep 'x'`" = "" ] && X="No" || Y="Yes"

echo $X