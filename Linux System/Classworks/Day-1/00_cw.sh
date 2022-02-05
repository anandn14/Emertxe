<<Documentation
Name: Anand N
Date: 01-10-2021
Descreption: Permiter tio find perimeter of rectangle
sample i/o: length (5) & breadth(5)
sample o/p: Perimeter of gthe rectangle is 20

Documentation
#!/bin/bash

read -p "Enter length & breadth:" length breadth #<----- Prompting & reading the values
Perimeter=`echo "2*($length+$breadth)" | bc` #<----Finding the Perimeter

if [ $length -gt 0 -a $breadth -gt 0 ] #<----checking condition for -ve integer values
then	
	echo "Perimeter of rectanglr is $Perimeter"
else

	echo "Please Enter +ve integfer"
fi
