<<Documentation
Name: Anand N
Date: 25-10-2021
Descreption:Display the longest and shrtest user name
Sample #i/p: 18_largest_username.sh
Sample o/p: The longest name is: gnome-initial-setup
 	    shortest user name is: lp
Documentation
#!/bin/bash
#Display the longest and shrtest user name

var=(`cat /etc/passwd | tr -s " " | cut -d ":" -f 1`) #<---- fetching the file to the variable with user names
length=${#var[1]}   #<----length of user names
l=${#var[@]}  #<----- length of tha arguernts
for i in `seq 1 $((l-1))`   #<----- iterating file user names over the for loop
do
    if [ $length -lt ${#var[$i]} ] #<---- condition to check long length of the user name 
    then
        length=${#var[$i]}   #<---- checking longer length of user name from loop
        largest_username=${var[$i]} #<----- storing longer length of user name in variable
    fi  
done
short_length=${#var[1]}
for i in `seq 1 $((l-1))`   #<----- iterating file user names over the for loop
do
   if [ $short_length -gt ${#var[$i]} ]  #<---- condition to check short length of the user name 
   then
      short_length=${#var[$i]}     #<---- checking shorter length of user name from loop
      shortest_username=${var[$i]}   #<----- storing longer length of user name in variable
   fi  
done
echo "The Longest name is: $largest_username"
echo "The shortest name is: $shortest_username"

