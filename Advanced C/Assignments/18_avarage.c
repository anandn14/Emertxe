/*Documentation
Name: Anand N
Date: 02-01-2022
Description: To find the average of n numbers by taking input in 3 different ways.
Sample i/p: 18_avarage.c
Sample o/p:
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out 2.5 1.2 3.2 2 5
Select the method to calculate average:
1. Scan from keyboard
2. Proceed with provided command line arguments
3. Proceed with environment variable arguments
Enter your choice:  2
Entered elements are: 2.5 1.2 3.2 2 5 
The average of entered numbers: 2.6    */

#include <stdio.h>
#include <stdlib.h>
int my_atoi(const char *);          //<---- function prototype for my atoi
char *my_strtok(char *, char *);   //<----- function prototype for my string token

int main(int argc, char **argv)  //<---- main function definition command line arguments
{
    int a[100], num, choice, i, count = 0;    //<--- declared the int variables
    char * token, *arr, str[2] = " ";        //<--- declared the char variables
    float sum = 0;               //<--- initialized the float variable

    printf("Select the method to calculate average:\n1. Scan from keyboard\n2. Proceed with provided command line arguments\n3. Proceed with environment variable arguments\nEnter your choice:  ");
    scanf("%d", &choice);       //<---- reading the choice from user

    switch (choice)     //<----- validating the enterd user choice
    {
	case 1:       //<---- for keyboard enterd method
	    printf("Enter the total number of integers: ");
	    scanf("%d", &num);   //<---- reading the size of aarra from user

	    printf("Enter the elements: ");
	    for (i = 0; i < num; i++)
	    {
		scanf("%d", &a[i]);
		sum += a[i];         //<---- expression for calculting the sum of the entered number
	    }
	    printf("The average of entered numbers: %g\n", (sum / num));  //<--- calculating the avarage of the number & printnig resullt

	    break;
	case 2:      //<----- for comand line arguments method
	    if(argc <= 1)   //<---- validating the condition for argumrnt count is to be greater than 1
	    {
		printf("Enter appropriate number of arguments to calculate average through command line\n");
	    }
	    else
	    {
		printf("Entered elements are: ");
		for(i = 1; i < argc; i++)
		    printf("%s ",argv[i]);

		printf("\n");

		for(i = 1; i < argc; i++)
		    sum += my_atoi(argv[i]);  //<----- expression for adding the numbers

		printf("The average of entered numbers: %g\n", (sum / (argc - 1))); //<---- calculating the avarage of the number
	    }
	    break;
	case 3:
	    arr  = getenv("arr");   //<--- getting the enev variables
	    if (arr == NULL)   //<---- validating the arr name adrees is null or not
	    {
		printf("Export the values in envirnment,using name as --> arr\n");
	    }
	    else
	    {
		token = my_strtok(arr, str);   //<--- function calling my_token for splitting the string as token

		while( token != NULL )   //<--- iterating the string over the while loop it encounters upto NULL characters
		{
		    count++;         //<----- incrementing the count
		    a[count] = my_atoi(token);   //<--- function calling my_atoi for converting ascii to integers of each tokens
		    sum += a[count];        //<---- calculating the sum
		    token = my_strtok(NULL, str);  //<---- again function calling for my_strtok foe next token
		}
		printf("The average of entered numbers: %g\n", sum/count);
	    }
	    break;
	default:
	    printf("Invalid choice\n");
    }

    return 0;
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

char *my_strtok(char *str, char *delim)    //<----- function definition for my string token
{
    int i, j;
    static char *ptr;      //<----- declatred the static char variables
    static int ch; 

    if(str == NULL)    //<---- validating the condition string is equal to null charcatre
    {   
	str = ptr;   //<--- assigning the string to static variable pointer
    }   
    else
	ch = 0;
    for(i = 0; *(str + i) != '\0'; i++)  //<----itterating the for loop upto string null charcter encounters 
    {
	for(j = 0; *(delim + j) != '\0'; j++) //<-----iterating the loop upto delimitters null characters encoounters 
	{
	    if(*(str + i) == *(delim + j)) //<---- validating the condition comparing the string character with delimiter character 
	    {
		*(str + i) = '\0';     //<-----asiigning the null character
		i++;
		ptr = (str + i);
		return str;   //<--- returning the string
	    }
	}
    }
    if(*(str + i) == '\0' && ch == 0)    //<----if this condition true returns the string 
    {
	ch = 1;
	return str;      //<----returns the string of removing the delimiter character
    }
    return NULL;
}

