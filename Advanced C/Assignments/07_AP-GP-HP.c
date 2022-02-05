/*Documentation
Name: Anand N
Date: 10-11-2021
Description: WAP to read 3 numbers A R N. Generate AP,GP,HP
Sample i/p: 07_AP-GP-HP.c
Sample o/p:
Enter the first number A:3
Enter the common ratio R:2
Enter the number of terms N:5
AP series is:
3 5 7 9 11 
GP series is:
3 6 12 24 48 
HP series is:
0.333333 0.200000 0.142857 0.111111 0.090909 

Do you want to continue?(Y/y): y
Enter the first number A:-2
Enter the common ratio R:3
Enter the number of terms N:5
Error:invalid input, Enter only +ve numbers

Do you want to continue?(Y/y): y
Enter the first number A:1025 
Enter the common ratio R:3
Enter the number of terms N:5
Error:Entered number is out of range

Do you want to continue?(Y/y): n       */

#include<stdio.h>
int main()
{

	int i, range = 1;    //<-- declared the in variables
	char ch;            //<--- declared the char variable

	for (i = 0; i < 10; i++)    //<--- iterating the range over the loop
	{
		range = range * 2;     //<----expression for calculating the range 
	}

	do                   //<----- do-while for continue the process
	{
		int A = 0, R = 0, N = 0, res = 0, j=0;   //<--- declared the int variables
		float Hp = 0;  				   //<--- declared the float variable
		printf ("Enter the first number A:");      
		scanf ("%d",&A);                           //<--- reading the first number from user
		printf ("Enter the common ratio R:");
		scanf ("%d",&R);                           //<---- reading the ratio from user
		printf ("Enter the number of terms N:");
		scanf ("%d",&N);                          //<---- reading the number of terms from user

		if ( A > 0 && R > 0 && N > 0 )            //<---- validating the condition for enetered values to greater than 0
		{
			if ( A <= range && R <= range && N <= range )   //<--- validating the condition for enetered values to be in range 2^10
			{
				res = A;                   //<--- assigning A value to the res varisble as a temporary value
				printf("AP series is:\n");   
				for (j = 0; j < N; j++)    //<--- iterating the N value over the for loop
				{
					printf ("%d ",res);    //<---- printing the AP series
					res = res + R;         //<---- expression for adding the first number with the ratio  
				}
				res=A;                    //<---  assigning A value to the res varisble as a temporary value
				printf("\nGP series is:\n");
				for (j = 0; j < N; j++)		//<--- iterating the N value over the for loop
				{
					printf ("%d ",res);        //<---- printing the GP series
					res = res * R;             //<--- expression for multiplication of first number and ratio
				}
				res=A;                         //<--- assigning A value to the res varisble as a temporary value
				printf("\nHP series is:\n");
				for (j = 0; j < N; j++)       //<--- iterating the N value over the for loop
				{
					Hp = (float) 1 / res;    //<---- expresiion for HP calculation by making one of the operand as float
					printf ("%f ",Hp);       //<---- printing the HP series
					res = res + R;           //<---- expression for adding the first number with the ratio
				}
				printf ("\n");               //<---- printing the new line
			}
			else
			{
				printf ("Error:Entered number is out of range\n");
			}
		}
		else
		{
			printf ("Error:invalid input, Enter only +ve numbers\n");
		}
		printf ("\nDo you want to continue?(Y/y): ");       
		scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
	}while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
}
