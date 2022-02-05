<<Documentation
Name: Anand N
Date: 05-10-2021
Descreption:To find that calculates summ of odd integiers from m to n
Sample i/o: m(10) & n(20)
Sample o/p: 11 13 15....19 sum of odd integers is 75 

Documentation
#!/bin/bash
#WAP to print the numbers from m to n
read -p "Enter number:" m n #Prompting & reading the values
for i in `seq $m $n` # <---- using sequence it will print asigned numbers in sequence
do
    num=`expr $i % 2` #<----- expression for checking odd numbers
    if [ $num -eq 1 ]
    then
       	echo "$i"
	sum=$((sum+$i))  #<---- summing of all odd integers
    fi
done
echo "Sum of odd integers: $sum"
echo
