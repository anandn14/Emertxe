<<Documentation
Name: Anand N
Date: 16-10-2021
Description:lockdown file permission for particular directory
Sample i/p:Enter Dirname(LAB)
Sample o/p:
Before lock down
total 0
-rw-rw-r-- 1 anandn anandn 0 Oct 16 13:11 file1.sh
-rw-rw-r-- 1 anandn anandn 0 Oct 16 13:11 file2.sh
-rw-rw-r-- 1 anandn anandn 0 Oct 16 13:11 file3.sh
-rw-rw-r-- 1 anandn anandn 0 Oct 16 13:11 file4.sh
After lock down
total 0
-rw------- 1 anandn anandn 0 Oct 16 13:11 file1.sh
-rw------- 1 anandn anandn 0 Oct 16 13:11 file2.sh
-rw------- 1 anandn anandn 0 Oct 16 13:11 file3.sh
-rw------- 1 anandn anandn 0 Oct 16 13:11 file4.sh

Documentation
#!/bin/bash
#WAS to locks down the permission foe a particular directory

num=$1     #<---- prompting arguments from the command line

if [ $1 > 0 ]  #<---- checking the arguments passed or not 
then
    if [ -d $1 ] #<---- -d used for checking the entered argument is a Directory or not 
    then
	a=`ls -l $1`
	echo -e "Before locks down\n $a"
	chmod go+rw -R $1 #<---- -R for applying same changes to all files in the folder, Used texctual method remove the read and write permission of groups and others for directory files
	b=`ls -l $1`
	echo -e "After locks down\n $b"
    else
	echo "It's not a Directory"
    fi
else
    echo "Plaese Pass the Directory in command line"
fi
