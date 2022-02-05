<<Documentation
Name: Anand N
Date: 11-10-2021
Descreption: Read n & generate a pattern
Sample i/p:Enter num(1234+)
Sample o/p:Sum is: 10

Documentation
#!/bin/bash
#WAS read n & generate a pattern 

num=$@ #<---length of number
sum=${num:0:0}
sub=${num:0:1}
mul=1
div=${num:0:1}
len=${#num}
n=${num:0:4} #<--- offset method seperate the digits 
op=${num:4:1} #<--- offset method to sepearte the operator
echo "len of numner: $len"
var='^[+-]?[0-9.]+$' #<------validation for numbers
if [ $# -gt 0 ]
then
    if [[ $n =~ $var ]]  #<---- checkingi the numbers
    then
        if [ $n -gt 0 ]
        then
            case $op in
                +)
                    for i in `seq 0 $((len-1))`  #<---iterating over digites of number & finding sum
                    do
                        off=${num:$i:1} #<--- offset method to fetch each digit from num
                        sum=$((sum+$off))
                    done
                    echo "Sum is :$sum"
                    ;;
                -)
                    for i in `seq $((len-1))`  #<---iterating over digites of number & finding sub
                    do
                        off=${num:$i:1} #<--- offset method to fetch each digit from num
                        sub=$((sub-$off))
                    done
                    echo "Sum is :$sub"
                    ;;
                x)
                    for i in `seq 0 $((len-2))`  #<---iterating over digites of number & finding mul
                    do
                        off=${num:$i:1} #<--- offset method to fetch each digit from num
                        mul=$((mul * $off))
                    done
                    echo "Mul is:$mul"
                    ;;
                /)
                    for i in `seq 1 $((len-2))`  #<---iterating over digites of number & finding div
                    do
                        off=${num:$i:1} #<--- offset method to fetch each digit from num
                        div=`echo "scale=3; $div / $off" | bc`
                    done
                    echo "Div is:$div"
                    ;;
                *)
                    echo "Operator missing or invalid operator, Please pass the operator as last digit (+,-,x,/)"
                    ;;
            esac
        fi
    else
        echo "Enter only integer or real numbers"
    fi
else
    echo -e "Please pass the arguments\nUsage:08_operator_dependent.sh 2345+"
fi

