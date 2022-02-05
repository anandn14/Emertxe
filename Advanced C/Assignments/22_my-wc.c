/*Documentation
Name: Anand N
Date: 10-12-2021
Description: To write a program to count number of characters, words and lines, entered
through stdin buffer 
Sample i/p: 22_my_wc.c
Sample o/p:
hi hello
welcome
Lines == 2, Words == 3, Characters == 17

Do you want to continue?(Y/y): n   */


#include<stdio.h>
#include<stdio_ext.h>

int main()
{
    char ch;
    do
    {
	int i, characters = 0, words = 0, lines = 0;    //<---- declared the int variables 
	char c, p_char;                                //<--- declared the char variables
	__fpurge(stdin);     //<--- to clear the buffer
	while((c = getchar()) != EOF)    //<------reading the input from user 
	{
	    characters++;      //<---- incremts the characters and counting
	    if( c == '\n')     //<--- validating the condition character is equal to new line
	    {
		lines++;       //<----- counting the lines
	    }
	    if (c == ' ' || c == '\t' || c == '\n')     //<----validating the condition for charcter equal to space,tab or new line
	    {
		if( p_char != ' ' && p_char != '\t' )  //<---condition to check whether ther are multiple space then comparing with the previous one
		{	 
		    words++;      //<--- counting the words
		}
	    }
	    p_char = c;         //<--- assigning the charcters to variable p_char
	}

	printf("Lines == %d, Words == %d, Characters == %d\n", lines, words, characters);

	printf ("\nDo you want to continue?(Y/y): ");       
	clearerr(stdin);                          //<---- to clear the error
	scanf("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}
