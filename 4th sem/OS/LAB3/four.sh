#Write a Shell script to find the file with the maximum size in the current working directory. (without using sort command)
#!/bin/bash

# ls -rS | tail -1

files=`ls`

max_size=-1
max_file=""

for file in ${files[@]}; do 
    size=`stat -f "%m" $file`
    if [[ $size -gt $max_size ]]; then
        max_size=$size
        max_file=$file 
    fi 
done

echo "${max_file}"
