<<Documentation
Name: Anand N
Date: 10-10-2021
Descreption: Read n & generate a pattern
Sample i/:10 20
Sample o/p: 30

Documentation
#!/bin/bash
#WAS read n & generate a pattern 
read -p "Enter 2 numbers: " n1 n2  #<-------- promting and print the number from user
sum=0

var='^[+-]?[0-9.]+$' #<------validation for numbers
if [[ $n1 =~ $var && $n2 =~ $var ]]  #<---- checking Entered numbers are numbers or not
then
    sum=`echo "scale=2; $n1+$n2" | bc`   #<----- Expreission for summing the integers and real numbers used pipe cmd and bc 
    echo  "Sum is:$sum"
else
    echo "Please Enter only 2 integers or real numbers"
fi

