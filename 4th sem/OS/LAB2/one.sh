# Shell script to find X to the power n
#!/bin/bash

function pow {
	a=$1		# value of X
	b=$2		# value of n
	c=1		# c to count counter
	res=1		# res to store the result

	if ((b == 0)); then
		res=1
	fi

	if ((a == 0)); then
		res=0
	fi

	if ((a >= 1 && b >= 1)); then
		while ((c <= b)); do
			res=$((res * a))
			c=$((c + 1))
		done
	fi

	echo "$1 to the power $2 is $res"
}

echo Enter the number:
read X
echo Enter the power of $X:
read n

pow $X $n
