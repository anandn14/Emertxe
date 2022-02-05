<<Documentation
Name: Anand N
Date: 25-10-2021
Descreption:search user present in your system
Sample i/p: 33_replace-DEL.sh
Sample o/p: Before replacing
#include <stdio.h>
int main()
{
printf("Hello world\n")
	return 0;
}
After replacing
#include <stdio.h>
int main()
<------DEL---------->
printf("Hello world\n")
	return 0;
}


Documentation
#!/bin/bash
#WAS to replace 20% lines in a C file randomly & replace it with the pattern <--DEL-->

count=`cat $1 | wc -l`     #<-------counts the number of lines in a file
res=`expr $((count * 20)) / 100`  #<-----20% of lines are calculated
    echo "Before replacing"
    cat $1
if [ $# -eq 0 ] #<-----if the inputs are equal to 0
then
        echo "pass command line arguments"
	exit
fi
if [ $count -eq 0 ] #<-----counted lines of files 0 or not
then
    echo "$1 Empty file. So cant replace the string"
    exit 
fi
if [ -f $1 ] #<-----checking the file exists or not
then
    for i in `seq $res` #<-----for loop starts from 0 to $res
    do
	var=`shuf -i 1-$count -n1` #<----shuf -i random number generated and permanent change
	sed -i "$var s/.*/<------DEL---------->/" $1 #<------prints the line
	echo "After replacing"
	cat $1   #<---- Shows the content of file
    done
else
    echo "No such File" 
fi

