<<Documentation
Name: Anand N
Date: 02-10-2021
Descreption: To chechk perfect right triangle
Sample i/o:a(8) b(15) c(17) 
Sample o/p: Yes it is perfect right triangle 

Documentation
#!/bin/bash
#WAP given three sides of a triangle, to check whether the triangle is perfect right triangle
read -p "Enter 3 sides of triangle:" a b c #<----Prompting & reading the values

tri1=`echo "($c)^2" | bc` #<-----calculation of one side of triangle
tri2=`echo "($a)^2 + ($b)^2" | bc` #<-----calculation of 2 sides of triangle
if [ $tri1 -eq $tri2 ] #<-----checking hypotenious of triangle
then
	echo "Yes it is perfect right triangle"	
else
	echo "No it is not perfect right triangle"

fi
