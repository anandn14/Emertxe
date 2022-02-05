<<Documentation
Name: Anand N
Date: 24-10-2021
Descriptio: determine weather a give file systemor mount point is mounted
Sample i/o: 26_mounted_file.sh udev
Sample o/p:
File system udev is mounted on /dev and it is having 0% with 1689800KB free

Documentation
#!/bin/bash
#WAS to determine weather a give file systemor mount point is mounted

fs=(`df -h | tr -s " " | cut -d " " -f 1`)  #<---- fetching and separating the filasystem names using cut cmd then assigned in variable
use=(`df -h | tr -s " " | cut -d " " -f 5`) #<------ fetching and separating use space file and assigned to variable
used=(`df -h | tr -s " " | cut -d " " -f 6`) #<---- fetching and separating use spaced file and assigned to variable 
avlbl=(`df | tr -s " " | cut -d " " -f 4`) #<---- fetching and separating available space in file and assigned to variable
count=0
if [ $# -ne 0 ]  #<--- checking numbers of arguments passed or not
then
    for i in ${fs[@]}  #<---- filesystems are iterating over the for loop
    do  
        if [[ $1 = $i ]]  #<---- condition to check the entered file name is from  the file system
        then
            echo "File system ${fs[count]} is mounted on ${used[count]} and it is having ${use[count]} with ${avlbl[count]}KB free"
	    exit   
        fi
        count=$((count+1))
    done
        if [[ $1 != $i ]]   #<---- condition to check entered file name is not from the fetched file system
        then
            echo "$1 is not mounted"
            exit
        fi
else
    echo "please pass the file-system through command line argument"
fi


