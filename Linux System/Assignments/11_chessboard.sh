<<Documentation
Name: Anand N
Date: 14-10-2021
Descreption:To print the chessboard
Sample i/o: Enter
Sample o/p:
1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0
Documentation
#!/bin/bash
#WAP to print the chessboard

for row in `seq 8` # <------- iterate over the row(no_of lines)
do
    for col in `seq 8`  #<----iterate over col(no_of liines)
    do
	sum=$(($row+$col))    #<---- summing of row and col
	var=`expr $sum % 2`  #<---- used modulus for reminder 1 or 0
	if [ $var -eq 0 ]   #< ---- checking remineder 0 or 1
	then
	    echo -e -n "\e[47m" " "    #<---- for white color blocks
	else
	    echo -e -n "\e[40m" " "    #<----- for black color blocks
	fi
    done
    echo -e -n "\e[0m" " "            #<----- for normal color 
    echo # <----- to move cursor to next line, by default echo will print new line character(\n)
done
echo
