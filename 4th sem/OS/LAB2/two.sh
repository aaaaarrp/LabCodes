#Shell script to read 10 numbers from the user and to find the sum and average of the numbers
#!/bin/bash

echo Enter total numbers:
read N
i=1
sum=0
echo Enter the numbers:
while [ $i -le $N ]; do
  read num
  sum=$((sum + num))
  i=$((i + 1))
done
avg=$(echo $sum / $N)
echo $sum
echo "scale = 2; $avg / 1" | bc -l
