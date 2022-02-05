<<Documentation
Name: Anand N
Date: 05-10-2021
Descreptio: Print the fibnocci terms upto n
Sample i/o: n(7)
Sample o/p: 0 1 1 2 3 5 
 
Documentation
#!/bin/bash
#WAP to print the fibnocci terms upto n 
read -p "Enter number:" n #<------Prompting & reading the values
a=0
b=1
c=0
while [ $a -le $n ] # <---- checking the assigned number is less than given number
do
    echo -n " $a"
    c=`expr $a + $b`
    a=$b
    b=$c
done
echo 
