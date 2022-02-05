<<Documentation
Name: Anand N
Date: 04-10-2021
Descreption:To print the piatterns
Sample i/o: 5
Sample o/p:
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
Documentation
#!/bin/bash
#WAP to print thepatterns
for row in `seq 5` # <------- iterate over the row(no_of lines)
do
	for col in `seq 1 $row` # <------ to iterate over col(no_of_*o
	do
		echo -n " $col"
	done
	echo # <----- to move cursor to next line, by default echo will print new line character(\n)
done
