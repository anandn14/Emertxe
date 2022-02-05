<<Documentation
Name: Anand N
Date: 21-10-2021
Descreption:Print system info
Sample i/p: 13_system_info.sh
Sample o/p:1) Currently logged user
2) Your home directory
3) Your shell directoryi
4) OS name and version
5) Current working directory
6) Number of logged in
7) show all available shells in your system
8) Hard disk information
9) CPU information
10) Memory information
11) file system informaton
12) Currently running process

Enter choice: 2
/home/anandn-Your home directory

Plaese enter for continue [y/n]?
y   
1) Currently logged user
2) Your home directory
3) Your shell directoryi
4) OS name and version
5) Current working directory
6) Number of logged in
7) show all available shells in your system
8) Hard disk information
9) CPU information
10) Memory information
11) file system informaton
12) Currently running process

Enter choice: 15
Invalid option, Please Enter a valid option


Documentation
#!/bin/bash
#WAS to print the system info 
a=`echo  "1) Currently logged user\n2) Your home directory\n3) Your shell directoryi\n4) OS name and version\n5) Current working directory\n6) Number of logged in\n7) show all available shells in your system\n8) Hard disk information\n9) CPU information\n10) Memory information\n11) file system informaton\n12) Currently running process"`
echo -e $a       #<------ prinitng the details with choice numbers for users
echo         
read -p "Enter choice: " num     #<----- reading user choice number
case $num in      #<---- checking the choice and validate the user choice then gives the output of details
    1)
	echo "$USER-Currently logged user"  
	;;
    2)
	echo "$HOME-Your home directory"
	;;
    3)
	echo "$SHELL-Your shell directory"
	;;
    4)
	echo "`uname -or` -OS name and version"
	;;
    5)
	echo "`pwd`- Current working directory"
	;;
    6)
	echo "`who`-Number of logged in"
	;;
    7)
	echo "`cat /etc/passwd` show all available shells in your system"
	;;
    8)
	echo "`df`-Hard disk information"
	;;
    9)
	echo "`cat /proc/cpuinfo`-CPU information"
	;;
    10)
	echo "`cat /proc/meminfo`-Memory information"
	;;
    11)
	echo "`df` -file system informaton"
	;;
    12)
	echo "`ps` -Currently running process"
	;;
    *)
	echo "Invalid option, Please Enter a valid option"
esac
echo
echo "Plaese enter for continue [y/n]?"   #<---- asking the user to continue or not
read choice                               #<---- reading the user choice
if [ $choice = Y -o $choice = y ]         #<----- validating the condition of user for yes to continue
then
    while [ $choice != n ]    #<----- if user choice is no then it will come out from the loop
    do
	echo -e $a                  #<-----again shows the details with choice number
	if [ $choice = Y -o $choice = y ]  #<---- validatig the condition of yes or no
	then
	    echo
	    read -p "Enter choice: " num  #<---- asking user choice
	    case $num in      #<------ checking and validating the user choice then gives the output of details
		1)
		    echo "$USER-Currently logged user"
		    ;;
		2)
		    echo "$HOME-Your home directory"
		    ;;
		3)
		    echo "$SHELL-Your shell directory"
		    ;;
		4)
		    echo "`uname -r` -OS name and version"
		    ;;
		5)
		    echo "`pwd`- Current working directory"
		    ;;
		6)
		    echo "`who`-Number of logged in"
		    ;;
		7)
		    echo "`cat /etc/passwd` show all available shells in your system"
		    ;;
		8)
		    echo "`df`-Hard disk information"
		    ;;
		9)
		    echo "`cat /proc/cpuinfo`-CPU information"
		    ;;
		10)
		    echo "`cat /proc/meminfo`-Memory information"
		    ;;
		11)
		    echo "`df` -file system informaton"
		    ;;
		12)
		    echo "`ps` -Currently running process"
		    ;;
		*)
		    echo "Invalid option, Please Enter a valid option"
	    esac
	    echo
	    echo "Plaese enter for continue [y/n]?"   #<----- again asking the user for continue or not
	    read choice              #<----- reading the user choice
	else
	    exit               #<---- if user choice is n then exit from the loop
	fi
    done
fi
