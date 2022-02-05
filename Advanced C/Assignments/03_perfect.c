/*Documentation
Name: Anand N
Date: 03-11-2021
Descreption: Given number is perfect or not
Sample i/p: 03_perfect-nu.c
Sample o/p:
Enter the number: 6
Yes,Entered number is perfect number
Do you want to continue?(Y/y): y
Enter the number: 12
No, Entered number is not a perfect number
Do you want to continue?(Y/y): y
Enter the number: -6
Error:Invalid input,Enter only positive numbers 
Do you want to continue?(Y/y): Y
Enter the number: 1048577
Error:Entered number is out of range 
Do you want to continue?(Y/y): n             */

//Documentation
//WAP to check whether a given number is perfct or not

#include<stdio.h>
int main()        
{
    int i, range=1;    //<----- decLared the int variables  
	char ch;                    //<----- declared the char variable

	for ( i = 0; i < 20; i++)    //<---- iterating the limit over the for loop
	{
		range = range * 2;      //<---- expresion for calculatig the ramge of the number
	}

	do        //<---- used do-while loop for conntinueing the process         
	{
		int j, num, res, sum = 0;      	 //<---- declared the int variables

		printf("Enter the number: ");   
		scanf("%d",&num);     		 //<--- reading the number from user

		if ( num > 0 ) 			 //<---- validate the condition to check the number is greter than 0 or not
		{
			if ( num > 0 && num <= range )   //<--- validating the limit of positive number range
			{
				for ( j = 1; j < num; j++)    //<--- iterating the entered number over the for loop 
				{
					res = num % j;           //<---- expression for the calculating the modulus of the number each time
					if ( res == 0 )         //<---- validating the condition to check with the result
					{
						sum = sum + j;      //<--- expression for adding the result
					}
				}
				if ( sum == num )          //<---- validate the condition to compare the resultwith the enterd number
				{
					printf ("Yes,Entered number is perfect number\n");
				}
				else
				{
					printf ("No, Entered number is not a perfect number\n");
				}
			}
			else
			{
				printf ("Error:Entered number is out of range \n");
			}
		}
		else
		{
			printf ("Error:Invalid input,Enter only positive numbers \n");
		}

		printf("Do you want to continue?(Y/y): ");      
		scanf("\n %c",&ch);                          //<---- reading the user choice for continue the process
	}while (ch == 'Y' || ch == 'y');                 //<--- validate the condition of user choice yes or no

	return 0;
}

