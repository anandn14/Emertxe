<<Documentation
Name: Anand N
Date: 08-10-2021
Descreption: Read n & generate a pattern
Sample ip/:4
Sample o/p: 
1
2 3 
4 5 6
7 8 9 10 

Documentation
#!/bin/bash
#WAS read n & generate a pattern 
read -p "Enter the number: " n   #<-------- Read and print the number from user
if [ $n -ge 2 -a $n  -le 32 ]   #<-------- Checking the number range b/n 2 to 2^5
then
    sum=0
    for row in `seq $n`    #<------ assigned row for generting number sequence         
    do  
        for col in `seq $row`  #<------assigned col for generating number sequence
        do
            sum=$((sum+1))   #<----- Expression for summing the number in sequence
            echo -n  "$sum "
        done
        echo                      #<------ for creating next new line
    done
else
    echo "Number out of range please enter 2<number<2^5"
fi

