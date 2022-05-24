#shell script to find whether the given number is Armstrong or not
#!/bin/bash

echo "Enter the number:"
read number
function ams {
    temp=$number
    sum=0
    base=0
    while [ $number -gt $base ]; do
        reminder=$((number % 10))
        sum=$((sum + (reminder * reminder * reminder)))
        number=$((number / 10))
    done
    echo Sum is $sum
    if [ $sum == $temp ]; then
        echo "Yes, an Amstrong number"
    else
        echo "Not an Armstrong number"
    fi
}
result=$(ams $n)
echo "$result"
