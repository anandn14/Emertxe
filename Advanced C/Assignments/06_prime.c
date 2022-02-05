/*Documentation
Name: Anand N
Date: 21-11-2021
Description: WAP to find the median of two unsorted arrays
Sample i/p: 06_prime.c
Sample o/p:
	Enter the number: 30   
	The prime numbers are: 2 3 5 7 11 13 17 19 23 29 

	Do you want to continue?(Y/y): y
	Enter the number: -20
	Invalid Input

	Do you want to continue?(Y/y): y
	Enter the number: 1048579
	Entered number is out of range

	Do you want to continue?(Y/y): n   */

#include<stdio.h>
int main()
{
    int i, range = 1;
    char ch;
    for(i = 0 ; i < 20 ; i++)        //<---- iterating the range over the for loop
    {
	range = 2 * range;           //<---expression for calculating the range
    }

    do                           //<--- use do-while loop for continue the process
    {
	int n, i, k ,j = 0, mul = 0;
	printf("Enter the number: ");
	scanf("%d", &n);                     //<---- reading the number from user
	if ( n > 0)                         //<----- validating the condition for eneterd number to be +ve
	{
	    if (n > 0 && n <= range)        //<---- validating the the conditong enetered +ve number to be in the range
	    {
		int arr[n];                  //<--- declaring the array with size(n number) & its name 
		for(i = 1; i < n; i++)
		{
		    arr[i] = i + 1;            //<---- assigning the array elements with adding 1 of position
		}
		for(i = 1; i < n; i++)       //<---- iterating the array size over the for loop
		{
		    if(arr[i] != 0)          //<--- validating the condition array elements value not equal to the zero
		    {
			mul = arr[i] * arr[i];   //<--- expression for finding out the multiple of number
			for (j = mul; j <= n; j += arr[i]) //<--- iterqating the multiple of number in loop then storing in j
			{
			    arr[j-1] = 0;     //<---- making the result multiple of numabers 0 
			}
		    }
		}
		printf("The prime numbers are: ");
		for(i = 1; i < n; i++)
		{
		    if(arr[i] != 0)               //<------ validating the result array relements should not be zero
		    {
			printf("%d ",arr[i]);     //<---- printing the prime numbers 
		    }
		}
		printf("\n");
	    }
	    else
	    {
		printf("Entered number is out of range\n");
	    }
	}
	else
	{
	    printf("Invalid Input\n"); 
	}
	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;
} 
