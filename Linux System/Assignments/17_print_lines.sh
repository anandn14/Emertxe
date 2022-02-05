<Documentation
Name: Anand N
Date: 11-10-2021
Descreption:To printcontents of file from givenline to next given line number
Sample i/o: 5 3 File name
Sample o/p: 
line 5
line 6
line 7 

Documentation
#!/bin/bash
#WAS to printcontent of file from given line number to next given line number
echo "Enteerd arguments: $#" 
echo "Name of the file is: $3"

if [ $# -eq 0 ]   #<------ $# for counting the number of lines arguments
then
    echo "Please pass the file name in command line"
    exit
elif [ $# -eq 3 ]  #<------- chechking the arguments 3 or not
then
    if [ -f $3 ]  #<------ -f checking the file exist or not
    then
        if [ -s $3 ] #<------ -s for checking file have conetents or not
        then
            len=`wc -l < $3` #<------ for checking the length of lines in files
            n=$(($1+$2))    #<---- for chechking entered arguments filr line number in limit
            n2=$(($n-1))    #<----for file line numbers reducing    
            if [ $n -gt $len ] #<------ conditon to check file have greater than enteerd lines
            then
                echo "$3 having only $len lines, file should have atleast 14 lines" 
            else
                head -n $n2 $3 | tail -n $2  #<------- for printing enteer lines from the file
            fi
        else
            echo "its an empty file"
        fi
    else
        echo "It's not a regular file"
    fi  
else
    echo -e "Arguments missing!\n./17.filefilter.sh start line uptoline filename\nFor eg.17_filefilter.sh 5 5 <filez>"
fi 

