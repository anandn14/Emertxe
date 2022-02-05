<<Documentation
Name: Anand N
Date: 21-10-2021
Descreption:search user present in your system
Sample i/p: 32_user_oresent.sh anandn
Sample o/p: anandn is present

Documentation
#!/bin/bash
#WAS to search user present in your system

un=(`cat /etc/passwd | cut -d ":" -f1`)  #<----- fetching useranmes of systen to the variable
count=0
if [ $# -eq 0 ]   #<----- condition to checking argument passed or not
then
    echo "Error:Please pass the argument through command line"
    exit
fi
for i in ${un[@]}   #<---- iterating usernames of the system over the for loop
do
    if [ $1 = $i ]   #<---- checking the entered username is present or not
    then
        count=$((count+1))
    fi  
done
if [ $count -eq 1 ] #<---- condition for checking the username prsented or not 
then
    echo "$1" is present
else
    echo "$1" is not present
fi


