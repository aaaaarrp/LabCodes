#Shell script to count the number of vowels in the string
#!/bin/bash

printf "\n"
echo Given string:
cat textForFive.txt 
printf "\nVowels in the given string:\n"
grep -o -i [aeiou] textForFive.txt | wc -l