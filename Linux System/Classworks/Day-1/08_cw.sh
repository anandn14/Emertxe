<<Documentation
Name: Anand N
Date: 03-10-2021
Descreption:To prints if the first is multiple of second
Sample i/o:n1(45) & n2(5)
Sample o/p: Yes first is multiple of second

Documentation
#!/bin/bash
#WAP that reads in 2 integers & determines & prints if the first is a multiple of the second

read -p "Enter 2 integers:" n1 n2 #<-----Prompting & reading the values
mul=`expr $n2 % $n1` #<-----Checking first is multiple of second
if [ $mul -gt 0 ] 
then
	echo "Yes first is multiple of second"
else
	echo "No first is multiple of second"
fi
