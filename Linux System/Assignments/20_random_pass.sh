<<Documentation
Name: Anand N
Date: 22-10-2021
Descreption: Genearatin random 8 character password including alpha numeric characters
Sample i/o: 20_random_pass.sh
Sample o/p: k%nHi{iD

Documentation
#!/bin/bash
#WAS for generating random 8-character passwords including alpha numeric charecters

if [ $# -eq 0 ]  #<------ checking arguments if any argument passed it will exit
then
    cat /dev/urandom | tr -cd [:graph:] | head -c 8   #<----- from random file it will takes only numbers,alphabets & characters and give only 8 charcters
    echo
else
    exit
fi
