<<Documentation
Name: Anand N
Date: 22-10-2021
Descreption: Print each argument passed to the function
Sample i/o:25_recursion.sh Hi hello how are you?
Sample o/p: Hi
hello
how 
are 
you?

Documentation
#!/bin/bash
# use recursive function to print each argument passed throgh the function

function print()      #<---- function assigning
{
    arr=($@)
    off=${arr[@]:1:$#-1}   #<---- fetching the each arguments to the poition 1 through offset methode
    if [ $# -ge 1 ]    #<-----condtion for lenght of the arguments becomes 1 to stop the function
    then
	echo $1        #<----- print the arguments of position 1
	print $off       #<----- call the function to prnting the offseted arguments
    fi
}

print $@             #<----- call the function to printing the arguments

if [ $# -eq 0 ]    #< ------ checking for the arguments passed or not
then
    echo "Please pass the arguments"
fi
