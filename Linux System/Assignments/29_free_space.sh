<<Documentation
Name: Anand N
Date: 24-10-2021i
Descriptio: Display the names of any file-system which have less than 10% free space
Sample i/o: 29_free _space.sh
Sample o/p:Filesystem tmpfs have have lessthan 10% free space

Documentation
#!/bin/bash
#Display the names of any file-system which have less than 10% free space

fi=(`df  | tr -s " " | cut -d " " -f 5 | cut -d "%" -f 1`)  #<--- fetching the fields from the file sytem
fname=(`df | cut -d " " -f 1`)                 #<---- fetching the file name from the file system

for i in `seq 0 $((${#fname[*]}-1))`   #<----- file system iterating over the loop
do
    if [[ ${fi[$i]} -ge 90 ]]       #<----- condition to check the file system greater than 90
    then
	file=${fname[$i]}      #<---- storing the free space name of file in the file variable
	fi
    done
    echo "Filesystem $file have have lessthan 10% free space"
