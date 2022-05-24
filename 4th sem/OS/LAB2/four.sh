#Shell script to print all the divisors of a given integer
#!/bin/bash

echo Enter a number:
read num

echo "All divisor of this integer are: "

for (( i = 1; i <= $num; i++)); do
	if [[ $(($num % $i)) -eq 0 ]]; then   #if reminder is 0, its a divisor
		echo $i
	fi
done