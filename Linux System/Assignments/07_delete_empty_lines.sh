<<Documentation
Name: Anand N
Date: 19-10-2021
Descreption:Delete empty lines from a file
Sample i/o: 07_delete_empty_lines.sh (file name)
Sample o/p: Empty lines are deleted 


Documentation
#!/bin/bash
#WAS to delete empty lines from a file

if [ $# -gt 0 ]  #<------ checking arguments passed or not
then
    if [ -f $1 ]  #<----- checking file exist or not using file filter -f
    then
	if [ -s $1 ]  #<----- checking file have contents or not usimg file filter -s
	then
	    sed -i '/^[[:blank:]]*$/d' $1    #<-----using sed command with options -i and blank deleting all empty lines from the file
	    echo "Empty lines are deleted"
	else
	    echo "File is exis but its empty"
	fi
    else 
	echo "file is not exist"
    fi
else 
    echo "Please Pass the file name"
fi
