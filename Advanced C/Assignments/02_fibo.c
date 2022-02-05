/*Documentation
Name: Anand N
Date: 02-11-2021
Description: Generate fibbonacci numbers <= m 
Sample i/p: 02_fibo.c
Sample o/p:
	Enter the number: 15
	0 1 1 2 3 5 8 13 
	Do you want to continue?(Y/y): y
	Enter the number: -21
	0 1 -1 2 -3 5 -8 13 -21 
	Do you want to continue?(Y/y): y
	Enter the number: 1048577
	Error:Number out of range, please enter the value -2^20 < 'N' < 2^20
	Do you want to continue?(Y/y): y
	Enter the number: 0
	Error: Enter the number greater than 0
	Do you want to continue?(Y/y): n      */

//Documentation
//WAP to generate the fibbonacci numbers <= n

#include<stdio.h>
int main()        
{
	int i, num; 		 	//<----- Declared the int variables 
	char ch;  	 	 		//<--- Declred the char variable    
	int range = 1, range1 = 1;   	 //<---- declared the int variables

	for ( i = 0; i < 20; i++ ) 	 	//<---- iterating the limit over the for loop
	{
		range = range * 2;    		//<---- expression for calculating the +ve range limit
		//range1 = range * -1;  		//<---- expression for calculating the of -ve range limit
	}
	range1 = range * -1;  		//<---- expression for calculating the of -ve range limit
	do		 		         //<--- used do-while loop for continue the process
	{
		int a = 0, b = 1, c = 0, n;  	 //<--- declared the int variables
		printf("Enter the number: "); 	 //<--- printing the statement
		scanf("%d", &num);  		 //<--- reading the value from user
		if ( num != 0 )                  //<---- validating the condition for entered number is greater than 0 or not
		{
			if ( num > 0 && num <= range )  	 //<---- validating the codition to check the positive range 
			{
				printf("%d ",a);                 //<----- prinitng the value of a
				while ( c <= num ) 		  //<--- iterating the +ve entered value over the while loop 
				{
					c = a + b; 			 //<--- adding the previous 2 values 
					a = b;     			 //<---- assigned a value to the b value
					b = c;     			 //<----  assigned b values to the c value
					printf ("%d ",a );             //<---- printing the results 
				}
			}
			else if ( num < 0 && num >= range1 )   //<---- condition to check the negative range
			{
				printf ("%d ",a ); 		 //<----- prinitng the value of a

				while ( c >= num ) 		//<--- iterating the +ve entered value over the while loop 
				{
					c = a - b;                  //<--- subtracting the previous 2 values 
					a = b;                      //<---- assigned a value to the b value
					b = c;                      //<----  assigned b values to the c value
					n = a * -1;                //<---- used expression for avoid to print the next +ve number
					if ( num <= n )            //<---- validating the condition
					{
						printf ("%d ",a);       //<--- printing the results
					}
				}
			}
			else
			{
				printf ("Error:Number out of range, please enter the value -2^20 < 'N' < 2^20");
			}
		}
		else
		{
			printf ("Error: Enter the number greater than 0");
		}
		printf ("\nDo you want to continue?(Y/y): ");       
		scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
	}while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

	return 0;
}

