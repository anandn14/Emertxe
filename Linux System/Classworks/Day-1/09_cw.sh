<<Documentation
Name: Anand N
Date: 03-10-2021
Descreption: To calculate the BMI
Sample i/o: Weight(73) & Height(1.6)
Sample o/p: BMI is Normal

Documentation
#!/bin/bash
#WAP to calculate the BMI
read -p "Enter Weight & Height:" w h #<-----Prompting & reading the Weight & Height
H=`expr $h*$h | bc`
BMI=`expr $w/$H | bc`   #<----calculating the BMI
echo "BMI is:$BMI"
if [ `echo "$BMI > 18.5" | bc` -eq 1 ] #<-----checking BMI for Underweight
then
	if [ `echo "$BMI > 18.5" | bc` -eq 1 -a `echo "$BMI < 24.9" | bc` -eq 1 ] #<-----checking the BMI for Normal
	then
		echo "It is Normal"
	elif [ `echo "$BMI > 25" | bc` -eq 1 -a `echo "$BMI < 29.9" | bc` -eq 1 ] #<-----checking the BMI for Overweight 
	then
		echo "It is Overweight"
	elif [ `echo "$BMI > 30" | bc` -eq 1 ] #<-----checking the BMI for Obese
	then
		echo "It is Obese"
	fi
else
	echo "It is Underweight"
fi
echo 
echo "Underweight: lessthan 18.5"
echo "Normal: between 18.5 and 24.9"
echo "Overweight: between 25 and 29.9"
echo "Obese: 30 or greater"
