<<Documentation
Name: Anand N
Date: 01-10-2021
Descreption: Permiter tio find perimeter of rectangle
sample i/o: length (5) & breadth(5)
sample o/p: Perimeter of gthe rectangle is 20

Documentation
#!/bin/bash

read -p "Enter length & breadth:" length breadth #<----Prompting & reading values
Perimeter=`echo "2*($length+$breadth)" | bc` #<----expression for perimeter
echo "Perimeter of rectanglr is $Perimeter"
