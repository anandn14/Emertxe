<<Documentation
Name: Anand N
Date: 10-10-2021
Descreptio: Print the fibnocci terms upto n
Sample i/o: n(7)
Sample o/p: 0 1 1 2 3 5 
 
Documentation
#!/bin/bash
#WAP to print the fibnocci terms upto n 
read -p "Enter limit for fib series:" n  #<------Prompting & reading the number from user
a=0
b=1
c=0
var='^[+-]?[0-9]+$'     #<------- For validating numbers    

if [[ $n =~ $var ]]     #<----- Checking enteered number is number or not
then
    if [ $n -lt 0 ]     #<----- Conditon for -ve numbers
    then
        echo "Please Enter only +ve numbers"
    elif [ $n -gt 0 ]   #<----- Condition for +ve numbers
    then
        while [ $a -le $n ] # <---- checking the assigned number is less than given number
        do
            echo -n " $a"
            c=`expr $a + $b`
            a=$b
            b=$c
        done
        echo
    fi  
else
    echo "Only Enter numbers"
fi
