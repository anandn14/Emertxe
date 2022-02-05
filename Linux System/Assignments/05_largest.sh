<<Documentation
Name: Anand N
Date: 16-10-2021
Description:compare larger integer from a 'n' number of arguments 
Sample i/p: 05_larger.sh (2 5 6 1 8 7)
Sample o/p:Largest number is:8
          

Documentation
#!/bin/bash
#WAS to compare larger integer from a 'n' nymber of arguments 
Arr=$@ #<---length of number
n=$#
i=0
var='^[+-]?[0-9.]+$' #<------validation for numbers
if [ $n -gt 0 ]
then
    if [[ $n =~ $var ]]  #<---- checking the numbers
    then
	for j in $Arr    #<----- looping the arguments
	do
	    if [ $j -gt $i ]   #<------ comparing the arguments for j value is greather than i value
	    then
		i=$((i+1))     #<----- initially i is 0 then its incrmentd by 1 for comparision
		i=$j
	    fi
	done
	echo " Largest number is: $i"
    fi
else
    echo "No arguments passed"
fi

