<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To printall the even numbers from 1 to 100 
Sample i/o: 1..100
Sample o/p:2 4 6 8....100

Documentation
#!/bin/bash
#WAP to print all the even numbers from 1 to 100
read -p "Enter number:" m n #Prompting & reading the values

for i in `seq $m $n` # <---- using sequence it will print asigned numbers in sequence
do
	n1=`expr $i % 2`
	if [ $n1 -eq 0 ]
	then
	    echo -n "$i "
	fi
done
echo

