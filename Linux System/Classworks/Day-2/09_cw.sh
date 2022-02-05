<<Documentation
Name: Anand N
Date: 05-10-2021
Descreption:Find the factorial of entered number
Sample i/o: n(10)
Sample o/p:factorial of number is

Documentation
#!/bin/bash
#WAP to find the factorial of entered number
read -p "Enter number:" num  #<----Prompting & reading the values
fact=1
read num
for i in $num # <---- using sequence it will print asigned numbers in sequence
do
   fact=`expr $fact \* $i` #<---- Expression for factorial
done
echo "Factorial of given number is: $fact"
echo
