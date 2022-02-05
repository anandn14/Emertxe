<<Documentation
Name: Anand N
Date: 02-10-2021
Descreption:Given length & breadth coresponds to rectangle or square
Sample i/o: length(5) & breadth(5)
Sample o/p: Given length & breadth corresponds to square 

Documentation
#!/bin/bash
#WAp to check whether the given length & breadth corresponds to square or rectangle
read -p "Enter length & breadth:" l b #Prompting & reading the values
square=`echo "4*$l" | bc` #checking for square
rectangle=`echo "2*($l*$b)" | bc` #checking for rectangle
if [ $l -gt 0 -a $b -gt 0 ] #checking number is between 30 & 40
then
	if [ $square -gt 0 ]
	then 
		echo "Given length & breadth corresponds to square"
	elif [ $rectangle -gt 0 ]
	then
		echo "Given length & breadth corresponds to rectangle"
	fi
else

	echo "Please enter +ve integer"
fi
