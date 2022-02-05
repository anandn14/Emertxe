<<Documentation
Name: Anand N
Date: 14-10-2021
Descreption:print given number in reverse order
Sample i/p:Enter num(12345)
Sample o/p:Revrsed number is- (54321)

Documentation
#!/bin/bash
#WAS to print given number in reverse order

num=$1     #<---- prompting arguments from the command line
rev=0
var='^[+-]?[0-9.]+$' #<------validation for numbers
if [ $1 > 0 ]   #<------ checking the arguments passed or not
then
    if [[ $num =~ $var ]]
    then
	if [ $num -gt 9 ]  #<----checking the entered number is multidigit or not
	then
	    while [ $num -gt 0 ]
	    do
		a=`expr $num % 10`  #<----- expression for calculating modulus of entered number
		num=$(($num/10))     #<----- Number divided by 10
		rev=`expr $rev \* 10`   
		rev=$((rev+a))      #<----- Gives the result of reversed number
	    done
	    echo "Reversed number is: $rev"
	else
	    echo "Plaese Enter multidigit number"
	fi
    else 
	echo "Please Enter numbers only"
    fi
else
    echo "Plaese Pass the arguments"
fi
