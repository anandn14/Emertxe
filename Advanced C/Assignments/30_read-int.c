/*Documentation
Name: Anand N
Date: 07-12-2021
Description: To write a function read_int to read an integer  
Sample i/p: 30_read_int.c
Sample o/p:
Enter the num:215gfr
number = 215
Do you want to continue(y/Y):y
Enter the num:gftr24
number = 0
Do you want to continue(y/Y):y
Enter the num:252/-
number = 252
Do you want to continue(y/Y):y
Enter the num:--554
number = 0
Do you want to continue(y/Y):y
Enter the num:vtg
number = 0
Do you want to continue(y/n):n     */

#include<stdio.h>
#include<stdio_ext.h>

int read_int(char *); //<--- function prototypefor read int

int main()
{
    char option;    //<--- declared char function
    do
    {
	int n;   //<--- declared the int variable
	char c;
	printf("Enter the num:");
	__fpurge(stdin);   //<--- to clear the buffer
	n = read_int(&c);    //<--- function calling for read int
	__fpurge(stdin);   //<--- to clear the buffer
	printf("number = %d",n);  

	printf("\nDo you want to continue(y/Y):");
	scanf("%c", &option);       //<---- reading the option from user for continue
	getchar();                 
    }while(option == 'y' || option == 'Y');  //<---- valifdating the condition for user choice

    return 0;
}

int read_int(char *ch)    //<--- function body for read int
{
    int i, n = 0, flag = 1;    //<-- declared & initialized the int variables

    for(i = 0; (*ch = getchar()) != '\n'; i++)
    {
	if(i == 0 && *ch == '-' || *ch == '+')  //<---- validating condition for first character is to be + or -
	{
	    if(*ch == '-')
		flag = -1;   //<-- if first char is - then setiing the flag to -1
	    continue;
	}
	if (*ch >= '0' && *ch <= '9')     //<---- validating the condition for character is to be number or not
	{
	    n = (n * 10) + (*ch - '0');  //<--- number subtracting with the equivalent ascii number then storing int n variable
	}
	else
	{
	    break;  //<--- if charcter is not a number then break the loop
	}
    }
    return n * flag;  //<--- returning the result
}
