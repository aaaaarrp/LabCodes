#Shell script to reverse the string without using in-built functions
#!/bin/bash

echo Enter a string:
read str

reverse=""

for (( i = ${#str} - 1; i >= 0; --i)); do 
	reverse=$reverse${str:i:1}    #extracting single single character from string.
	
done

echo "Reverse of $str is: $reverse"