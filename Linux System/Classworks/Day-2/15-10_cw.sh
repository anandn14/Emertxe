<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To print the piatterns
Sample i/o: 5
Sample o/p:
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
Documentation
#!/bin/bash
#WAP to print thepatterns
for row in `seq 5` # <------- iterate over the row(no_of lines)
do
	for col in `seq $row`  #<----iterate over col(no_of_*o
	do
	    echo -n "$row "
done
	echo # <----- to move cursor to next line, by default echo will print new line character(\n)
done
echo
