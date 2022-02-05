<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To print all the even numbers between m&n,excluding m&n
Sample i/o:m m(1) & n(20)
Sample o/p:12 14 16 18

Documentation
#!/bin/bash
#WAP to print all the even numbers between m & n,excluding m & n
read -p "Enter number:" m n #Prompting & reading the values

for i in `seq $m $n` # <---- using sequence it will print asigned numbers in sequence
do
    num=`expr $i % 2` #<------ expression forfinding out even numbers
    if [ $num -eq 0 ]
    then
	if [ $i -eq $m -o $i -eq $n ] #<----Condition for excluding the m & n
	then
	    a=0
	else
	    echo -n "$i "
	fi
    fi
done
echo
