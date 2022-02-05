/*Documentation
Name: Anand N
Date: 13-12-2021
Description: Read a string and reverse string without storing in another array using recursive method and non-recursive method 
Sample i/p: 40_string_rev.c
Sample o/p:
1.Iterative Method
2.Recursive Method
Enter your choice: 2
Enter the string: Hello Welcome!
Reversed string is: !emocleW olleH

Do you want to continue?(Y/y): n    */

#include<stdio.h>
void rev_iterative(char *);           //<--- function prototypefor string reverse iterative type
void rev_recursive(char *, int, int); //<---- function prototypefor string reverse recursive type 

int main()
{
    char ch;
    do             //<--- do-while loop for continue process
    {
	int choice;
	int option;
	char str[100];           //<--- declared the stringstring name with size

	printf("1.Iterative Method\n2.Recursive Method\nEnter your choice: ");
	scanf("%d",&choice);     //<---- reading the choice from user

	switch(choice)      //<---selecting the choce from switch case
	{
	    case 1:         //<--- for string reverse iterative method
		printf("Enter the string: ");
		scanf("%*c%[^\n]", str);    //<--- reading the string from user
		rev_iterative(str);        //<---- function calling for string reverse
		printf("Reversed string is: %s\n", str);
		break;
	    case 2:         //<--- for string reverse recursive method
		printf("Enter the string: ");
		scanf("%*c%[^\n]", str);   //<--- reading the string from user
		int i = 0,len = 0;        
		for (int i = 0; str[i] != '\0'; i++)    //<---- for finding out the length of the string
		{
		    len++;       //<---- length incremebt and storing in variable
		}
		rev_recursive(str, len, i);    //<---- function calling for string reverse 
		printf("Reversed string is: %s\n", str);
		break;
	    default:
		printf("Please Enter valid options only");
	}

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;
}

void rev_iterative(char *str)    //<--- function definition for string revrse iterative method
{
    char t;
    int i = 0,len = 0;
    for (i=0; str[i] != '\0'; i++)   //<--- finding out the string length
    {
	len++;     
    }

    for(i = 0; i < (len - 1);i++)    //<--- iteratuve the string lenghth over the for loop
    {
	t = str[i];               //<---asssigned string char to the temp variable
	str[i] = str[len - 1];    //<--- assigned next string char to the ith element
	str[len - 1] = t;         //<--- assigning the last elements to the temp value //swapping method
	len--;	
    }
}

void rev_recursive(char *str, int len,int i)    //<--- function definition for the string reverse recursivr method
{
    char t;
    if(i < (len/2))              //<--- base condition for the function
    {
	t = str[i];                  //<---- swapping method
	str[i] = str[len - i - 1]; 
	str[len - i - 1] = t;
	i++;
	rev_recursive(str,len,i);     //<---- again function calling for the string reverse
    }
}
