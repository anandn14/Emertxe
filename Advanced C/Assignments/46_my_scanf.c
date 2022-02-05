/*Documentation
Name: Anand N
Date: 09-01-2022
Description: WAP to implement my_scanf() function
Sample i/p: 46_my_scanf.c
Sample o/p:
Enter a number: 256
Enter a char: a
Enter a string: Anand
Enter a float value: 2.3
Enter a double value: 12.369

Entered Number is: 256
Entered Character is: a
Entered String is: Anand
Entered Float number is: 2.300000
Entered double number is: 12.369000

Do you want to continue?(Y/y): n    */

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<stdio_ext.h>

int my_atoi(const char *);    //<---- function prototype for atoi
void my_scanf(char *, ...);     //<----- function prototype for my_scanf
int main()
{
    char choice;
    do  
    {   
	/* decalred the variables */
	int num;               
	char ch, str[50];   
	float num1;
	double num2;

	__fpurge(stdin);    	        //<---- to clear the input buffer
	
	printf("Enter a number: ");
	my_scanf("%d ", &num);          //<---- function calling for my_scanf for reading the int value
	
	printf("Enter a char: ");
	my_scanf("%c ", &ch);           //<---- function calling for my_scanf for reading the char value
	
	printf("Enter a string: ");
	my_scanf("%s ", str);           //<---- function calling for my_scanf for reading the string value
	
	printf("Enter a float value: ");
	my_scanf("%f ", &num1);         //<---- function calling for my_scanf for reading the float value
	
	printf("Enter a double value: ");
	my_scanf("%lf ", &num2);         //<---- function calling for my_scanf for reading the double value

	printf("\n");

	/* priting the read input */
	printf("Entered Number is: %d\n", num);  
	printf("Entered Character is: %c\n",ch);
	printf("Entered String is: %s",str);
	printf("Entered Float number is: %f\n",num1);
	printf("Entered double number is: %lf\n",num2); 

	printf ("\nDo you want to continue(Y/y)?: ");       
	my_scanf ("%c",&choice);                          //<----- reading the user choice for continue the process or not
    }while (choice == 'Y' || choice == 'y');                 //<----- validating condition of user choice
    return 0;
}

void my_scanf(char *format, ...)     //<----  function definition for my_scanf
{
    va_list ap;                      //<---- pointer pointing to firsit argumnet
    int *num = 0;
    char *ch, *str, buff[50] = {0};
    float *f;
    double *d;
    va_start(ap,format);          //<---- move to first unknown arguement with reference to previous known arguement

    while(*format)        //<---- iterating the arguments over the while loop
    {
	if(*format == '%')    //<---- validating the condition for format is % or not 
	{
	    format++;         //<---- incrementing the value of arguments
	    if(*format == 'd')   //<---- validating the condition for integer format d
	    {
		num = va_arg(ap,int *);         //<----- va_arg-return unknown value and move to next unknow
		fgets(buff,20,stdin);          //<----- it will takes the string characters form the buff 
		*num = my_atoi(buff);        //<---- function calling for atoi	
		format++;
	    }
	    if(*format == 'c')       //<----- validating the condition for char format is c
	    {
		ch = va_arg(ap,char *);    
		*ch = getchar();        //<----- getting the char value
		format++;
	    }
	    if(*format == 's')       //<----- validaitng the condition for strig format s
	    {
		getchar();
		str = va_arg(ap,char *);    //<----- arguments as string array
		fgets(str,50,stdin);         //<---- getiing the string from the buffer
		format++;
	    }
	    if(*format == 'f')     //<------ validating the condition for float format f
	    {
		f = (float *)va_arg(ap, double *);   //<---- arguments are type catsted as float if not it will take it as double
		fgets(buff,50,stdin);
		*f = atof(buff);      //<---- used atof for converting the ascii to float value
		format++;
	    }
	    if(*format == 'l')    //<--- validating the condition for double format l
	    {
		format++;
		if(*format == 'f')  //<----- validating the next format is f for double
		{
		    d = va_arg(ap, double *);
		    fgets(buff,50,stdin);
		    *d = atof(buff);    //<---- atof for converting the ascii to float value
		    format++;
		}
	    }
	}
	else
	{
	    format++;
	}
    }
    va_end (ap); 	//<----- ends the ap usage
}

int my_atoi(const char *ptr)     //<----- function defination for atoi 
{
    int n = 0, flag = 1;
    while (*ptr != '\0')      //<--- string iterating over the while loop 
    {
	if (*ptr == '-')      //<---- validating the condition for -ve sign
	{
	    flag = -1;       //<---- setting the flag to -1
	    ptr++;           //<---- incrementing the ptr for checking the next char
	}
	if (*ptr >= '0' && *ptr <= '9')    //<---- valiadating the condition for passed characters are numbers or nit
	{
	    n = (n * 10 ) + (*ptr - 48);   //<----- converting the ascii to integer
	    ptr++;
	}
	else
	{
	    break;
	}   
    }   
    return n * flag;          //<----- returning the integer value to the calling function
}

