/*Documentation
Name: Anand N
Date: 15-11-2021
Description: WAP to print all possible combinations of given string  
Sample i/p: 49_combinations.c
Sample o/p:
Enter a string: AND
AND
ADN
NAD
NDA
DNA
DAN

Do you want to continue?(y/Y): y
Enter a string: aab
Please enter distinct characters

Do you want to continue?(Y/y): n    */

#include<stdio.h>
void combination(char *, int, int);    //<----- function prototype for combination
void swap(char *, char *);             //<------ function prototype for swaping

int main()
{
    char ch;               //<------ initializing character variable
    do                    //<----- do-while loopfoe continuw the process
    {   
	char str[20];                   //<---- declared the strin with the size
	printf("Enter a string: ");
	scanf("%s",str);                //<---- reading the string from user
	int i, j, len = 0, count = 0;   //<---- declared the int varables

	for(i = 0; str[i]!='\0'; i++)   //<----- itearating the string over the loop  to find the length of string
	{   
	    len++;
	}   
	for(i = 0; i < len; i++)         //<----- loop for checking the distinct character
	{   
	    for(j = (i+1); j < len; j++)   //<---- iterating the loop for 
	    {   
		if(str[i] == str[j])  //<--- validating the condition for distinct characters in the string
		{   
		    count = 1;       //<---- assigning the count to 1
		    break;
		}   
	    }   
	}
	if(count == 0)            //<----- validating the condition count is equal to 0
	    combination(str, 0, len-1);    //<------ function call for combination
	else
	    printf("Please enter distinct characters\n");

	printf("\nDo you want to continue?(y/Y): ");    
	scanf("\n%c",&ch);                         //<--- reading choice from user
    }while(ch == 'y' || ch == 'Y');               //<---- validating the condtion for user choice for continue the process or not
    return 0;
}

void combination(char *str, int first, int last)   //<----- function definition for combination
{
    if(first == last)                   //<----- validating the condition to check if starting and ending character is same
	printf("%s\n",str);
    else
    {
	for(int i = first; i <= last; i++)     //<---- iterating the first to last char over the for loop                           
	{
	    swap((str+first), (str+i));        //<-----function calling for swaping the first character
	    combination(str, first + 1, last); //<----- recursive function call for combination
	    swap((str+first), (str+i));      //<----- again funnction calling for swapping for backtracing 
	}
    }
}

void swap(char *a,char *b)   //<----- function definition for swaping
{
    char temp=*a;         //<---- assigning the a value the the temp variable
    *a=*b;                //<---- assigning the b value to the a variable
    *b=temp;              //<----- assigning the temp value to the b variable
}

