<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To print the numbers from m to n
Sample i/o: 10 20
Sample o/p:10 11 12 13 .... 20

Documentation
#!/bin/bash
#WAP to print the numbers from m to n
read -p "Enter number:" m n #Prompting & reading the values

for i in `seq $m 1 $n` # <---- using sequence it will print asigned numbers in sequence
do
	echo "$i "
done

