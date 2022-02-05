<<Documentation
Name: Anand N
Date: 05-10-2021
Descreption:To check a nuber is pelindrome or not
Sample i/o: 58285
Sample o/p: Yes it is pelidrome number 

Documentation
#!/bin/bash
#WAP to check the numer is pelidrome or not
read -p "Enter number:" n #Prompting & reading the values

    sum1=0
while [ $n -gt 0 ]
do
    a=`expr $n % 10`
    b=`expr $n / 10`
    sum=`expr sum \* 10`
    sum1=$(($sum+$a))
echo "number is not pelidrome"
done  
    if [ $sum1 -eq $n ]
    then
    echo " number is pelindrome"
else 
echo "number is not pelidrome"
    fi

