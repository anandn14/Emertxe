<<Documentation
Name: Anand N
Date: 10-10-2021
Descreption: To calculate the BMI
Sample i/o: Weight(45) & Height(1.5)
Sample o/p: You are Normal

Documentation
#!/bin/bash
#WAP to calculate the BMI
read -p "Enter the Weight in Kg:" w      #<-----Prompting & reading the Weight 
read -p "Enter the Height in meters:" h  #<-----Prompting & reading the Height

var='^[0-9.]+$' #<------ validating the numbers

if [[ $w =~ $var && $h =~ $var ]]       #<------ Checking integers and real numbers equal to enteered values
then
    H=`expr $h*$h | bc`
    BMI=`expr $w/$H | bc`   #<----calculating the BMI
    echo "BMI is:$BMI"
    if [ `echo "$BMI >= 18.5" | bc` -eq 1 ] #<-----checking BMI for Underweight
    then
        if [ `echo "$BMI >= 18.5" | bc` -eq 1 -a `echo "$BMI <= 24.9" | bc` -eq 1 ] #<-----checking the BMI for Normal
        then
            echo "You are Normal"
        elif [ `echo "$BMI >= 25" | bc` -eq 1 -a `echo "$BMI <= 29.9" | bc` -eq 1 ] #<-----checking the BMI for Overweight 
        then
            echo "Yor are Overweight"
        elif [ `echo "$BMI >= 30" | bc` -eq 1 ] #<-----checking the BMI for Obese
        then
            echo "You are Obese"
        fi
    else
        echo "You are Underweight"
    fi
    echo                              #<----- For craeting new line these are diplayed only if the correct inputs are passed
    echo "Underweight: lessthan 18.5"
    echo "Normal: between 18.5 and 24.9"
    echo "Overweight: between 25 and 29.9"
    echo "Obese: 30 or greater"
else
    echo -e "Invalid input \nPlaese Enter positive values"  
fi

