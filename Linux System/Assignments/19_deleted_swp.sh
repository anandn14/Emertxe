<<Documentation
Name: Anand N
Date: 24-10-2021i
Descriptio:delete all the .swp files found in your system or dir
Sample i/o: 19_delete_display_swp.sh
Sample o/p:
.swp files are found:
/home/anandn/ECEP/C/Classwork/.01_ex.c.swp
/home/anandn/ECEP/LS/Classwork/.37_array-sum.sh.swp
/home/anandn/ECEP/LS/Assignments/axz.swp
/home/anandn/ECEP/LS/Assignments/axc.sh.swp
/home/anandn/ECEP/LS/Assignments/axc.swp

Documentation
#!/bin/bash
#WAS to delete all the .swp files found in your system or directory

if [ $#  -gt 0 ]  #<---- checkinf the arguments passed or not
then
    if [ -d $1 ]   #<---- checking passed arguments ids directorty or not
    then
	l=`find $1 -name "*.swp"`   #<--- finding the all .swp files
	d=${#l}                 #<---- counting the number of swp files
	if [ $d -eq 0 ]       #<----- condition to checking the files nu,ber
	then
	    echo "no .swp file found in $1"
	else
	    rm $l              #<---- deleteing the al swp files using remove command
	    echo "All swp files are deleted"
	fi
    else
	echo "$1 no such file or directory"
    fi
elif [ $# -eq 0 ]    #<--- checking the condtion for arguments 0 or not
then
    l=`find ~ -name "*.swp"`    #<---- finding all thye .swp files from home directory used ~
    echo -e ".swp files are found:\n$l"   #<---- printing all the list of .swp files foun from the system
fi
