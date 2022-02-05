<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To print the piatterns
Sample i/o: 5
Sample o/p:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
Documentation
#!/bin/bash
#WAP to print thepatterns

sum=0
for row in `seq 5` # <------- iterate over the row(no_of lines)
do
	for col in `seq 1 $row ` #<----iterate over col(no_of_*o
	do
	    sum=$((sum+1))
		echo -n "$sum "

	done
	echo # <----- to move cursor to next line, by default echo will print new line character(\n)
done
echo
