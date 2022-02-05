<<Documentation
Name: Anand N
Date: 24-10-2021
Description: Count the number of users with IDs
Sample i/o: 30_user_id.sh 0 100
Sample o/p:Total count of user ID between 0 to 100 is:16


Documentation
#!/bin/bash
#Count the number of users with user IDs between the givenrange on the system

i=`(cat /etc/passwd | cut -d ":" -f 3)`  #<-----fetching the user IDs from the /etc/passwd file
count=0
if [ $# -eq 0 ]     #<----- cheking the number of arguments passed or not if not it will show default
then
    echo "Total count of user iID betwwen 500 to 10000 is:2" #<---- printing defult user ID
else
    if [ $# -eq 2 ]   #<---- checking for entered number of arguments 2 or not
    then
	if [ $1 -lt $2 ]  #<---- checking the valid range if between $1 & $2
	then
	    for ID in $i   #<---- iterating user ID over the for loop
	    do
		if [ $ID -gt $1 -a $ID -lt $2 ]  #<--- cheking in between range of entered numbers
		then
		    count=$((count+1))  #<---- counting the user IDs inbetween enetered range
		fi
	    done
	    echo "Total count of user ID between $1 aand $2 is : $count"  #<---- printing the total count of IDs
	else
	    echo "Invalid range please enter the valid range through cmd line"
	fi
    else
	echo -e "Please pass two arguments through cmd line\n Usage:30_user_id.sh 100 200"
    fi
fi
