<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To find the smallest and largest nuuber
Sample i/o: numbers 15 48
Sample o/p: smallest number is 15

Documentation
#!/bin/bash
#WAP to find the smallest and largest of entered n numbers
read -p "Enter length:" num #Prompting & reading the values
read n
for i in $n      # <---- using sequence it will print asigned numbers in sequence
do
	if [ $i -gt $num ]
	then
	    largest=$i
	fi
	if [ $i -lt $num ]
	then
	    smallest=$i
	fi

done
echo "Laargest number is: $largest"
echo "Smallest number is: $smallest"
