<<Documentation
Name: Anand N
Date: 02-10-2021
Descreption:Product of 2 given number is odd or even
Sample i/o: a(5) & b(4)
Sample o/p: product of 2 given number is even 

Documentation
#!/bin/bash
#WAP to check whether the product of two given number is odd or even

read -p "Enter 2 numbers:" a b #<-----Prompting & reading the values
product=`expr $a \* $b` #<-----Multiplication of numbers
echo "Product is: $product" 
result=`expr $product % 2` #<-----checking product is even or odd

if [ $result -eq 0 ]  
then
	echo "Given number product is Even"
else
	echo "Given number product is Odd"
fi
