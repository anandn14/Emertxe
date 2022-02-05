<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To find the sum and average of number
Sample i/o: n1=10 n2=20
Sample o/p: Sum is 30

Documentation
#!/bin/bash
#WAP to find the sum & average of n numbers entered

read -p "Enter numbers:" num
sum=0
for n in $num
do
	sum=$((sum+n))
	echo "Sum is:$sum"
	avg=$(($sum/n))
	echo "Average is:$avg"
done
