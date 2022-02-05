<<Documentation
Name: Anand N
Date: 22-10-2021
Descreption: Print each argument passed to the function
Sample i/o:25_recursion.sh Hi hello how are you?
Sample o/p: Hi
hello
how 
are 
you?

Documentation
#!/bin/bash

function print()      #<---- function
{
    a=($@)
    if [ $# -gt 0 ]    #<----- checking for arguments passed or not
    then
        if  [ $1 = 0 ] 
        then
            a=${a[@]:1:$#-1}
            echo $1
            print $a
            print $a
        fi
            print $a
    else
        echo "Please passs the arguments through the commnd line"
    fi  
            print $a
}
print $@

