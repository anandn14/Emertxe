<<Documentation
Name: Anand N
Date: 02-10-2021
Descreption:Check number is multiple of 5
Sample i/o: n(15)
Sample o/p: Entered number is multiple of 5 

Documentation
#!/bin/bash
#WAP to check whether the entered number is multiple of 5

read -p "Enter a number:" n #<----Prompting & reading the values
Res=`expr $n % 5` #<------checking number is multiple of 5
if [ $Res -eq 0 ]  
then
	echo "Entered number is multiple of 5"
else
	echo "Entered number is not a multiple of 5"
fi
