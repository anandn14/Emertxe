<<Documentation
Name: Anand N
Date: 16-10-2021
Descreption:Arithmetic aclculator using command line
Sample i/p:04_calculator.sh (25 + 41)
Sample o/p: 25 + 41 = 67

Documentation
#!/bin/bash
#WAS to Arithmetic calculator usind command line 

num=$@ 		#<---Prompting arguments from command line
n=$#  		#<----- Total number of arguments
op=${num:3:2} 	#<--- offset method to seperate the operator
echo $op
var='^[+-]?[0-9.]+$' #<------validation for numbers
if [ $n -gt 0 ]
then
    if [[ $n =~ $var ]]  #<---- checking the numbers
    then
	if [ $n -eq 3 ]
	then
	    case $2 in      #<---- checking for the operator
		+)
		    sum=`echo $1 + $3 | bc`
		    echo "$1 $2 $3 = $sum"
		    ;;
		-)
		    sub=`echo $1 - $3 | bc`
		    echo "$1 $2 $3 = $sub"
		    ;;
		x)
		    mul=`echo $1 \* $3 | bc`
		    echo "$1 $2 $3 = $mul"
		    ;;
		/)
		    div=`echo "scale=2; $1 / $3" | bc`
		    echo "$1 $2 $3 = $div"
		    ;;
		*)
		    echo "Operator missing or invalid operator (+,-,x,/)"
		    ;;
	    esac
	else 
	    echo -e "Please pass the 3 arguments \nUsage:04_calculator.sh 25 + 41"
	fi
    else 
	echo "Please Enter only integer or real numbers"
    fi
else
    echo -e "Please pass the arguments through commnd line.\nUsage:04_calculator.sh 25 + 41"
fi

