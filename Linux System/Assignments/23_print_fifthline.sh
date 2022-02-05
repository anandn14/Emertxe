<<Documentation
Name: Anand N
Date: 11-10-2021
Descreption:To print the 5th line of a file
Sample i/o: File name
Sample o/p: Shows the 5th line of the file 

Documentation
#!/bin/bash
#WAS to print the 5th line of a file passes through command line
echo "Enteerd arguments: $#"
echo "name of the file is: $1"

if [ $# -eq 0 ]   #<------ $# for counting the number of lines arguments
then
    echo "Please pass the file name in command line"
    exit
elif [ $# -eq 1 ]  #<------- chechking the arguments 1 or more than 1
then
    if [ -f $1 ]  #<------ -f checking the file exist or not
    then
        if [ -s $1 ] #<------ -s for checking file have conets or not
        then
            len=`wc -l < $1` #<------ for checking the length of lines in files
            if [ 5 -gt $len ] #<------ conditon to check file have greater than 5 lines
            then
                echo "$1 having only $len lines so can't print 5th line" 
            else
                head -n 5 $1 | tail -n 1  #<------- for printing the 5th line from the file
            fi
        else
            echo "its an empty file"
        fi
    else
        echo "No such a file"
    fi
else
    echo "Please enter a one file"
fi

