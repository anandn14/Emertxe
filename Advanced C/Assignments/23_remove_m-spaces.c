/*Documentation
Name: Anand N
Date: 12-12-2021
Description: Replace each string of one or more blanks by a single blank
through stdin buffer 
Sample i/p: 23_remove_m-spacesc.c
Sample o/p:
Enter string: 		Hey     hello
String with reduced spaces is: Hey hello

Do you want to continue?(Y/y): y
Enter string: functions      pointers          		arrays
String with reduced spaces is: functions pointers arrays

Do you want to continue?(Y/y): n   */

#include<stdio.h>
#include<string.h>
void remove_space(char *);
int main()
{
    char ch;
    do
    {
	char str[100];     //<---- declared string1 with size

	printf("Enter string: ");
	scanf("%[^\n]", str);    //<---reads the string from user


	remove_space(str);      //<----- function calling for sring squeezing form str2 to str1
	printf("String with reduced spaces is: %s\n",str);

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c%*c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;
}

void remove_space(char *str)
{
    int i = 0;               //<-- initialize the int variable
    while(str[i] != '\0')    //<---- iterating the string over the while loop
    {
	if(str[i] == '\t' || str[i] == ' ' && str[i+1] == ' ')   //<----validating the condition for spacecs and tabs inbetwee strings
	{
	    int k = i;               //<--- declared the variable
	    while(str[k] != '\0')    //<---- againn iterating the string over the loop
	    {   
		str[k] = str[k + 1];    //<---assigning the next string position to the previous position
		k++;                   //<---- incrementig the positions
	    }
	}
	else
	    i++;                      //<---- incremention iof i string positions    
    }
}
