/*Documentation
Name: Anand N
Date: 03-01-2022
Description: WAP to implement my_printf() function
Sample i/p: 45_my_printf.c
Sample o/p:
Enter a number, char, string: 125 a Anand
Output: 125 a Anand

Do you want to continue?(Y/y): n    */

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<stdio_ext.h>

int my_itoa(int, char *);    //<---- function prototype for itoa
void my_printf(char *, ...);     //<----- function prototype for my printf
int main()
{
    char choice;
    do  
    {   
	int num = 0;                       //<----- declared the int type variables
	char ch, str[20];      //<---- declared tyhe char type variables
	my_printf("Enter a number, char, string: ");    //<----- function calling for my printf
	scanf("%d %c %s", &num, &ch, str);           //<------ reading inputs from user

	my_printf("Output: %d %c %s", num, ch, str);   //<----- function calling for my printf

	my_printf ("\nDo you want to continue(Y/y)?: ");       
	scanf ("\n%c",&choice);                          //<----- reading the user choice for continue the process or not
    }while ( choice == 'Y' || choice == 'y' );                 //<----- validating condition of user choice
    return 0;
}

void my_printf(char *format, ...)     //<----  function definition for my printf
{
    va_list ap;                      //<---- pointer pointing to firsit argumnet
    int num = 0;
    char ch, *str, buff[20] = {0};
    va_start(ap,format);          //<---- move to first unknown arguement with reference to previous known arguement

    while(*format)        //<---- iterating the arguments over the while loop
    {
	if(*format == '%')    //<---- validating the condition for format is % or not 
	{
	    format++;         //<---- incrementing the value of arguments
	    if(*format == 'd')   //<---- validating the condition for format is d
	    {
		num = va_arg(ap,int);         //<----- va_arg-return unknown value and move to next unknow
		my_itoa(num,buff);        //<---- function calling for itoa	
		fputs(buff,stdout);          //<----- it will takes the string characters form the buff 
		format++;
	    }
	    if(*format == 'c')       //<----- validating the condition for format is c
	    {
		ch = (char)va_arg(ap,int);    //<----- typecasted as char of the int type arguments
		putchar(ch);        //<----- printing the char value
		format++;
	    }
	    if(*format == 's')       //<----- validaitng the condition for format is s
	    {
		str = va_arg(ap,char *);    //<----- arguments as string array
		puts(str);           //<---- printing the string
		format++;
	    }
	}
	else
	{
	    putchar(*format);
	    format++;
	}
    }
}
int my_itoa(int num, char *str)    //<---- function defination for itoa
{
    int rem, n, i, len = 0;    
    n = num;

    if(n < 0)          //<---- validating the condition for whether negative number is entered
    {   
	n = n * -1;    
	str[0] = '-';    //<--- assigning the first char to -ve sign
	len = 1;
	num = n;        //<---- assigning the n to the num 
    }   

    while (n != 0)          //<---- iteraring the number over the loop for getting the length of integer entered
    {   
	len++;
	n = n / 10; 
    }   

    for (i = 0; i < len; i++)         //<----  iterating the length over the for loop
    {   
	if (num != 0)      //<--- validating the condition number is not equal to the 0
	{
	    rem = num % 10;    //<---- taking the mod of the number
	    num = num / 10;   //<---- expression for calculating the number weather completly divisible by 10
	    str[len - (i + 1)] = rem + '0';   //<---- expression for converting the integer number to the ascii value
	}
    }   

    str[len] = '\0';                  //<----- assigning the '\0' to the string
}
