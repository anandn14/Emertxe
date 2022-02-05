<<Documentation
Name: Anand N
Date: 01-10-2021
Descreption:heck Enteerd number is between 30 & 40
sample i/o: number(35)
sample o/p: 35 is between 30 & 40

Documentation
#!/bin/bash
#WAP to check whether the entered number is between 30 & 40

read -p "Enter a Number:" n #<------Prompting & reading the number

if [ $n -gt 30 -a $n -lt 40 ] #<----checking number is between 30 & 40
then	
	echo "$n is between 30 & 40"
else

	echo "$n is not between 30 & 40"
fi
