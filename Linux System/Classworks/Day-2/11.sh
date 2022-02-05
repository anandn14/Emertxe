<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To print the piatterns
Sample i/o: 5
Sample o/p:
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
Documentation
#!/bin/bash
#WAP to print thepatterns

for row in `seq 8` # <------- iterate over the row(no_of lines)
do
    for col in `seq 8`  #<----iterate over col(no_of_*o
    do
	    var=`expr $col % 2`
	echo -n "$var"
    done
    echo # <----- to move cursor to next line, by default echo will print new line character(\n)
done
echo
