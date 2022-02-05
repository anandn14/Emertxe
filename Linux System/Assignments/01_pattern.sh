<<Documentation
Name: Anand N
Date: 08-10-2021
Descreption: Read n & generate a pattern
Sample i/:4
Sample o/p: 
1
1 2
1 2 3
1 2 3 4 

Documentation
#!/bin/bash
#WAS read n & generate a pattern 
read -p "Enter the number: " n   #<-------- Read and print the number from user
if [ $n -ge 2 -a $n  -le 32 ]   #<-------- Checking the number range b/n 2 to 2^5
then

    for row in `seq $n`    #<------ assigned row for generting number sequence         
    do  
        for col in `seq $row`  #<------assigned col for generating number sequence
        do
            echo -n  "$col "
        done
        echo                      #<------ for creating next new line
    done
else
    echo "Number out of range please enter 2<number<2^5"
fi
