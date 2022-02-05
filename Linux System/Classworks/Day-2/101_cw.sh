<<Documentation
cc
Name: Anand N
Date: 05-10-2021
Descreptio: Print the fibnocci terms upto n
Sample i/o: n(5)
Sample o/p: 0 1 1 2 3 

Documentation
#!/bin/bash
#WAP to print the numbers from m to n
read -p "Enter number:" n #<------Prompting & reading the values
a=0
b=1
c=0
for i in $n # <---- if entered number is lessthan assigned value
do
    if [ $c -le $i ]
    then
    c=`expr $a + $b`
    a=$b
    b=$c
    echo -n "$c"
    fi
done
echo
