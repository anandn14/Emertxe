<<Documentation
Name: Anand N
Date: 22-10-2021
Descreption: For each directory in the $PATH, display the number of executable files in that directory
Sample i/o: 31_exicutable_path.sh
Sample o/p:
Current dir: /usr/local/sbin
Current count: 0
Current dir: /usr/local/bin
Current count: 0
Current dir: /usr/sbin
Current count: 370
Current dir: /usr/bin
Current count: 1816
Current dir: /sbin
Current count: 2186
Current dir: /bin
Current count: 3632
Current dir: /usr/games
Current count: 3636
Current dir: /usr/local/games
Current count: 3636
Current dir: /snap/bin
Current count: 3639
Current dir: /home/anandn/Bin
Current count: 3642
Total: 22557

Documentation
#!/bin/bash
# For each directory in the $PATH, display the number of executable files in that directory

path=(`echo $PATH | tr ':' '\n'`)  #<--Fetcingh each directories from PATH variable
count=0
total=0
for f in `seq 0 $((${#path[@]}-1))`   #<------ all path directories make array and iterative over 6the for loop
do
    echo "Current dir: ${path[f]}"   
    cd ${path[$f]}                #<----- current directory path changing
    l=(`ls | tr " " "\n"`)        #<----- listing all the directories
    for ccount in `seq 0 $((${#l[@]}-1))` #<---- all the list make array and iterating over the for loop
    do
	if [ -x ${l[$ccount]} ]    #<----- condition for checking the files are having the executable permission 
	then
	    count=$(($count+1))    #<---- counting the files and incrementd by 1
	fi
    done
    echo "Current count: $count"
    total=$(($total+$count))          #<----- total count of the executable files
done
echo "Total: $total"
