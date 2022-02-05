<<Documentation
Name: Anand N
Date: 05-10-2021
Descreption:To sum of enteerd numbers
Sample i/o: n (6 5)
Sample o/p: sum is:11 

Documentation
#!/bin/bash
#WAP to print the numbers from m to n
read -p "Enter number:" n #Prompting & reading the values

for i in $n # <---- using sequence it will print asigned numbers in sequence
do
	sum=$((sum+$i))  #<---- summing of all odd integers
done
echo "Sum of: $sum"
echo
