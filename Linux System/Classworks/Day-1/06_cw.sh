<<Documentation
Name: Anand N
Date: 03-10-2021
Descreption:To check year leap or not
Sample i/o: 2020
Sample o/p: Yes it is a leap year 

Documentation
#!/bin/bash
#WAP to check whether the given year is leap or not
read -p "Enter a year:" year #<-----Prompting & reading the values
Y=`expr $year % 4` #<-----checking for leap year
if [ $Y -eq 0 ] 
then
	echo "$year is a leap year"	
else
	echo "$year is not a leap year"

fi
