<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To prin the numbers from 1 to 100
Sample i/o: 100
Sample o/p: 1 2 3 .....100

Documentation
#!/bin/bash
#WAP to print the numbers from 1 to 100
read -p "Enter number:" n #Prompting & reading the values

for i in `seq $n` # <---- using sequence it will print asigned number times
do
	echo -n "$i "
done

