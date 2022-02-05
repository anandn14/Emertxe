<<Documentation
Name: Anand N
Date: 05-10-2021
Descreption:To check a nuber is prime or not
Sample i/o: 2
Sample o/p: Yes it is prime number 

Documentation
#!/bin/bash
#WAP to check the numer is pelidrome or not
read -p "Enter number:" n #Prompting & reading the values
i=2
f=0
a=`expr $n / 2`
    b=`expr $n % 2`
	c=$(($i+1))

while [ $i -lt $b ]
do
    if [ $b -eq 0 ]
    then
	f=1
    fi
    done
	if [ $f -eq 1 ]
	then
	echo "number is not prime number"
    else	
    echo "number is prime number"
    fi


