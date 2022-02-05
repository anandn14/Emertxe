<<Documentation
Name: Anand N
Date: 24-10-2021
Descriptio:Print contents of a directory without ls command 
Sample i/o: 27_output.sh
Sample o/p:/home/anandn/ECEP
C Cpp DS EL LI LS MC Qt


Documentation
#!/bin/bash
#WAS to print contentsof a directory without ls command

if [ $# -eq 0 ]   #<----- checking for arguments passed or not
then
    echo *     #<----- no arguments passed means it will print the contnts of list from current directory
    exit
fi
if [ $# -gt 0 ]    #<-----checking for the argiuments passed  
then
    for i in $@    #<--- directories itearating over the for loo[
    do
	if [ -d $i ] #<---- checking for entered arguments are directories or not
	then
	    cd $i    #<---- using cd command to change that enetered directoris path 
	    echo "$i"  #<----- printing the directory path name
	    echo *    #<---- printing the list of contents from the directory
	else
	    echo "cannot access $i : No such file or directory"
	fi
    done
fi
