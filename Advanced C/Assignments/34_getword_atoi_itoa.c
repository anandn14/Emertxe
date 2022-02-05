/*Documentation
Name: Anand N
Date: 14-12-2021
Description: Implement getword, atoi, itoa functions
Sample i/p: 34_getword_atoi_itoa.c
Sample o/p:
Select the option:
1.getword
2.atoi
3.itoa
Enter your choice: 1
Enter a word: Hello Welcome
word = Hello
Length of word = 5
Do you want to continue?(y/Y): y
Select the option:
1.getword
2.atoi
3.itoa
Enter your choice: 2
Enter a numeric string: 12345asdf
String to integer is = 12345
Do you want to continue?(y/Y): y
Select the option:
1.getword
2.atoi
3.itoa
Enter your choice: 3
Enter the number: asd124
0
Do you want to continue?(y/Y): n    */

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
unsigned int getword(char *);   //<---- Function prototype for getword 
int my_atoi(const char *);     //<---- Function prototype for atoi 
int my_itoa(int, char *);    //<---- Function prototypre for itoa

int main()
{
    char ch;             //<----- declaring the local variables
    int option;
    do
    {
	int num = 0, ret, len = 0;
	char str[50];                  //<---- declaring the string name with size
	printf("Select the option:\n1.getword\n2.atoi\n3.itoa\nEnter your choice: ");
	scanf("%d", &option);         //<---- reading the choice from user

	switch (option)         //<---- switch case for validating the user choice
	{
	    case 1:                       //<---- for getword operation
		printf("Enter a word: ");
		scanf("%*c%[^\n]", str);       //<---- reading the string from user
		len = getword(str);              //<---- calling get word function
		printf("\nLength of word = %d", len);
		break;
	    case 2:        //<----- for atoi operation
		printf("Enter a numeric string: ");
		scanf("%s", str);                      //<---- reading the string fom user
		num = my_atoi(str);                      //<---- calling atoi function 
		printf("String to integer is = %d", num);
		break;
	    case 3:        //<--- for itoa operation
		printf("Enter the number: ");
		scanf("%d", &num);             //<--- reading the number from user
		if (num >= 1)                //<--- validating the condition for eneterd number is ggreater than 1
		{
		    len = my_itoa(num, str);                 //<----- calling my atoi function 
		    printf("The length is: %d", len);
		}
		else
		    printf("0"); 
		break;
	    default:
		printf("Invalid oprtion,Please enter valid option");
	}
	printf("\nDo you want to continue?(y/Y): ");
	__fpurge(stdin);                     //<---- to clear the input buffer
	scanf("\n%c", &ch);                  //<--- reading the choice from user
    }while (ch == 'Y' || ch == 'y');        //<---- validating the choice for continue the process
    return 0;
}

unsigned int getword(char *str)   //<---- function defination for getword 
{
    int i, j, len = 0;     //<----declaring the int variables

    for (i = 0; *(str + i) != '\0'; i++);   //<---- to get the length of the string
    for (j = 0; j <= i; j++)             //<----- iterating the strng length over the loop,to get the first word till space or '\0' and store in othe string
    {
	if (*(str + j) == ' ' || *(str + j) == '\0')    ///<---- validating the condition for string get til space or '\0'
	{
	    break;
	}
	else
	{
	    len++;                 //<----- if not incrementing the string
	}
    }
    *(str + j) = '\0';           //<---- assigning the '\0' to the string
    printf("word = %s", str);
    return len;                  //<----- returning the length of the string to calling function
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


int my_itoa(int num, char str[])    //<---- function defination for itoa
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
    printf("The string = %s\n", str);

    return len;     //<------ retirning the length value to the calling function
}

