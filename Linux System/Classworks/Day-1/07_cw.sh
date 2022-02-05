<<Documentation
Name: Anand N
Date: 03-10-2021
Descreption:To find totsl marks of student
Sample i/o: m1(78) m2(85) m3(86)
Sample o/p: He is Excellent

Documentation
#!/bin/bash
#WAP given 3 marks of a student, to find the total,if the total <50 he fails,if it is between 51 & 100 he is average, above 100 ecellent
read -p "Enter 3 marks of student:" m1 m2 m3 #<----Prompting & reading the values

Total=$((m1 + m2 + m3))
echo "Result is:$Total"
if [ $Total -gt 50 ] #<-------checking result is Fail or not
then
	if [ $Total -gt 50 -a $Total -lt 100 ] #<------Checking for Result Average
	then
		echo "He is Average"
	elif [ $Total -gt 100 ] #<-----Checking for Result Excellent
	then
		echo "He is Excellent"
	fi	
else
	echo "He is failed"
fi
