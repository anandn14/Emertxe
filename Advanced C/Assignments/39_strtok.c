/*Documentation
Name: Anand N
Date: 17-12-2021
Description:  To implement strtok function
Sample i/p: 39_my_strtok_rev.c
Sample o/p:
Enter the string: hi,hello/welcome.asde
Enter the delimitter: ,./
Splitting string into tokens:
hi
hello
welcome
asde
Do you want to continue?(Y/y): n    */

#include<stdio.h>
#include<string.h>
char *my_strtok(char *, char *);   //<---- function protype for my string token
int main()
{
    char ch;
    do
    {
	char str[100];       //<----- declared the strin1 with size
	char del[10];        //<----- declared the string to as delimitter

	printf("Enter the string: ");
	scanf("%[^\n]",str);          //<----- reading the string from user
	printf("Enter the delimitter: ");
	scanf("%s",del);              //<---- reading the delimitter from user
	char *tok;
	printf ("Splitting string into tokens:\n");
	tok = my_strtok(str,del);     //<---- function calling for token
	while (tok != NULL)           //<---- tokens iterarting over the loop upto encounters the last null character
	{
	    printf ("%s\n",tok);
	    tok = my_strtok(NULL, del);    //<---- function calling fro next tokens
	}
	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
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
