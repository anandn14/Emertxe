<<Documentation
Name: Anand N
Date: 13-10-2021
Descriptio:Print the length of each and every string using array
Sample i/o: Hi Hello
Sample o/p: Hi-2
            Hello-5 
 
Documentation
#!/bin/bash
#WAP to print the length of each and evey string using array 

arg=$@  #<---- prompting arguments from cmd line
n=$#    #<----counting the total number of arguments
if [ $n -gt 0 ]   #<---- condition to check arguments passed or not
then
    for i in ${arg[@]}   #<---- looping all the arguments
    do 
	echo "Length of string: $i - ${#i}"  #<--- checking and print the length of every string
    done
else
    echo "Please pass the arguments through command line"
fi
