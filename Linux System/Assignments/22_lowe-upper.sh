<<Documentation
Name: Anand N
Date: 20-10-2021
Descreption: Convert string lower to upper and upper to lower
Sample i/o: 22_lower_upper.sh (filename)
Sample o/p: 
name of the file is: file.sh
1-Lower to Upper
2-Upper to lower
Please selct option: 1
HI HELLO WORLD
Please selct option: 2
hi hello world


Documentation
#!/bin/bash
#WAS to convert string lower to uppernd upper to lower
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
	    echo "name of the file is: $1"
	    echo "1-Lower to Upper"
	    echo "2-Upper to lower"
	    read -p "Please selct option: " n
	    case $n in
		1)
		    cat $1 | tr [:lower:] [:upper:]   #<----- using tr command translating the case lower to upper
		    ;;
		2)
		    cat $1 | tr [:upper:] [:lower:]   #<----- using tr command translating the case upper to lower
		    ;;
		*)
		    echo "Please selct only 1 or 2"
		    ;;
	    esac
	else
	    echo "its an empty file"
	fi
    else
	echo "No such a file"
    fi
else
    echo "Please enter one file name"
fi 
