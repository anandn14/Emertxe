<<Documentation
Name: Anand N
Date: 22-10-2021
Descreption:create an infinite feedback loop
Sample i/o: 24_redirection
Sample o/p: hi hello
hi hello
hi hello
hi hello
..
..
..

Documentation
#!/bin/bash
#use pipes or redirection to create an infinite feedback loop
if [ $# -gt 0 ]  #<------ checking arguments passed or not
then
    if [ -f $1 ]  #<----- checking file exist or not using file filter -f
    then
	if [ -s $1 ]  #<----- checking file have contents or not usimg file filter -s
	then
	    tail -f $1 >> $1 | tail -f $1    #<----- redirection the file content through tail command
	else
	    echo " File is exis but its empty"
	    read -p "Enter string:" str       #<----- if file is exist but its empty then it will take the string from user
	    echo $str >> $1                   #<---- storing the string in file
	    tail -f $1 >> $1 | tail -f $1     #<---- redirection the file contnt through tail command:wq
	fi
    else 
	echo "file is not exist"
    fi
else 
    echo "Please Pass the file name"
fi
