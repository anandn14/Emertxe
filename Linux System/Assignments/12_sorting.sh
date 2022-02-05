<<Documentation
Name: Anand N
Date: 19-10-2021
Descreption:Sort given number in ascending or descending order 
Sample i/p:Enter number(2 5 6 1 8 7)
Sample o/p:Ascending order is: 1 2 5 6 7 8
           Descending order is: 8 7 6 5 2 1

Documentation
#!/bin/bash
#WAS to sort a given number in ascending or descending order 

Arr=($@)	#<---- Passing the arugumrnts through command line stored in variable
t=0
if [ $# -gt 0 ]   #<----- Checking the arguments passed or not through command line
then
	case $1 in    #<---- $1 is position of arguments for user choice
	    -a)       #<---- -a for Ascending the numbers
		if [ $2 -gt 0 ]   #<------ checking position of argument 2 is gtreater than 0 or not
		then
		for i in `seq $#`   #<---- number of arguments iterating over the loop
		do
		    for j in `seq $i $#`   #<----- again number of arguments iterating over the loop
		    do
			if [[ ${Arr[$j]} -lt ${Arr[$i]} ]] #<------ condition for copmarision between two numbers
			then
			    t=${Arr[$i]}          #<----- initially t value is 0 assigned i value to the t for swaping numbers
			    Arr[$i]=${Arr[$j]}    #<---- i values becomes value of j
			    Arr[$j]=$t            #<----- now, j value becomes value of t number is swaped now
			fi
		    done
		done
		echo -n "Ascending order of given number is:"
		for i in `seq $#`                 #<------ numbers of argumnts for iterating over loop
		do
		    echo -n " ${Arr[$i]}"       #<------ printing the ascending numbers
		done 
		echo
		fi
		;;

	    -d)			#<---- -d for Descending the numbers
		if [ $2 -gt 0 ]		#<------ checking position of argument 2 is gtreater than 0 or not
		then
		for i in `seq $#`	#<---- number of arguments iterating over the loop
		do
		    for j in `seq $i $#` 		#<----- again number of arguments iterating over the loop
		    do
			if [[ ${Arr[$j]} -gt ${Arr[$i]} ]] 	#<------ condition for copmarision between two numbers
			then
			    t=${Arr[$i]}	#<----- initially t value is 0 assigned i value to the t for swaping numbers
			    Arr[$i]=${Arr[$j]}	#<---- i values becomes value of j
			    Arr[$j]=$t		#<----- now, j value becomes value of t number is swaped now
			fi
		    done
		done
		echo -n "Descending order of given number is:"
		for i in `seq $#`	#<------ numbers of argumnts for iterating over loo
		do
		    echo -n " ${Arr[$i]}"	#<------ printing the ascending numbers
		done 
		echo
		fi
		;;
	    *)
		echo -e "Please pass the choice\n Usage:12_sorting.sh -a/-d 11 2 4 55 6"
		;;
	esac
else
    echo -e "Please pass the arguments through command line\n Usage:12_sorting.sh -a/-d 11 2 4 55 6"
fi
