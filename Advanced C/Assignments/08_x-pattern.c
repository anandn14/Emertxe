/*Documentation
Name: Anand N
Date: 07-11-2021
Description:Print Hello in X format 
Sample i/p: 08_x-pattern.c
Sample o/p:
Enter the Number: 5
Hello    Hello 
 Hello  Hello  
  HelloHello  
 Hello  Hello  
Hello    Hello 

Do you want to continue?(Y/y): y
Enter the Number: 6
Hello     Hello 
 Hello   Hello  
  Hello Hello   
  Hello Hello   
 Hello   Hello  
Hello     Hello 

Do you want to continue?(Y/y): y
Enter the Number: 32
Error:Entered number out of range

Do you want to continue?(Y/y): y
Enter the Number: -5
Error:Enter only +ve number
Do you want to continue?(Y/y): n    */

//Documentation
//WAP to print Hello in X format

#include<stdio.h>
int main()        
{
	int i, r, c, n, range = 1;	    //<----- decLared the int variables  
	char ch;

	for ( i = 0; i < 5; i++)     //<--- iterating range of number 2^5 over the for loop
	{
		range = range * 2;      //<--- expression for cecking calculating the range
	}
	do
	{
		int n;
		printf ( "Enter the Number: ");      
		scanf ( "%d",&n);  		       //<---- reading the number from user
		if ( n > 0 )            	      //<---- validating the condition for enterd number is greater than 0 or not
		{
			if ( n < range )           //<---- validating the condition for enterd number in the range or not
			{
				for ( r = 1; r <= n; r++)    	//<---- iterating the row over the for loop
				{
					for ( c = 1; c <= n; c++)    	//<---- iterating the column  over the for loop
					{
						if ( (r == c) || (r + c) == ( n + 1))    //<--- validating the condition
						{
							printf ("Hello");     //<--- if codition is true then printing the statement hello 
						}
						if ( (r == c) && (r + c) == ( n + 1))    //<--- validating the condition
						{
							printf ("Hello");     //<--- if codition is true then printing the statement hello 
						}
						else
						{
							printf (" ");
						}
					}
					printf ("\n");            //<--- printing new line
				}
			}
			else
			{
				printf ("Error:Entered number out of range\n");
			}
		}
		else
		{
			printf ("Error:Enter only +ve number\n");
		}
		printf ("\nDo you want to continue?(Y/y): ");       
		scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
	}while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

	return 0;
}
