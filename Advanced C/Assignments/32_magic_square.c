/*Documentation
Name: Anand N
Date: 288888888-12-2021
Description: WAP to generate a n*n magic square (n is odd +ve no.)
Sample i/p: 32_magic_square.c
Sample o/p:
Enter a number: 3
   8    1    6 
   3    5    7 
   4    9    2 

Do you want to continue?(Y/y): y
Enter a number: 4
Enter only odd number
Do you want to continue?(Y/y): n    */

#include<stdio.h>
#include<stdlib.h>
void magic_sqr(int **, int);     //<---- function prototype for magic square
int main()
{
    char ch;    

    do        //<---- do-while loop for continue the process
    {
	int n, i, j;    //<---- declared the int variables

	printf("Enter a number: ");
	scanf("%d",&n);            //<---- reading the number from user
	int *arr[n];              //<--- declared the array pointer

	if ( n < 0)             //<---- validating the condition for number is positive or not
	    printf("Enter only positive odd number\n");
	else
	{
	    if ((n % 2) == 1)    //<--- validating the positive number even or odd
	    {
		for (i = 0; i < n; i++)   //<---iterating the size over the for loop
		{
		    arr[i] = malloc(n * sizeof(int));    //<---- allocating the memory dynamically
		}
		for (i = 0; i < n; i++)  
		{   
		    if (arr[i] == NULL)    //<---- validating the condition for dynamically memory allocated or not
		    { 
			fprintf(stderr,"Unable to allocate the memory\n");
			return 1;
		    } 
		}

		magic_sqr(arr, n);     //<---- calling the function for magic square

		for (i = 0; i < n; i++)
		{
		    free(arr[i]);        //<---- frees the memery
		    arr[i] = NULL;       //<--- assgning the NULL to the array address
		}
	    }
	    else
		printf("Enter only odd number\n");
	}

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;
}

void magic_sqr(int **arr, int n)     //<----- function definition for magic square
{
    int sqr = n * n;              //<---- initialized the sqr variable, assigned the n * n
    int i = 0, j = (n / 2), k;   //<---- initialized the int variables

    for( k = 1; k <= sqr; k++)   //<----- iterating the sqr iver the for looop
    {
	arr[i][j] = k;          //<---- assigning the every numbers storing in the array
	i--;                   //<---- decrementing the i value
	j++;                  //<---- incrementing the j value
	if (k % n == 0)       //<----- validating the condition
	{
	    i = i + 2;      //<---- assigning the i value every 2 times
	    j--;            //<---- decrementing the j value
	}
	else
	{
	    if (j == n)       //<---- validating the condition for  j value is equal to the n value
	    {
		j = j - n;    //<---- assigning the j to the j - n value
	    }
	    else if (i < 0)   //<----- else validating the condition i value lesser than 0
	    {
		i = i + n;    //<----- assigning the i to the i + n value
	    }

	}
    }
    for (i = 0; i < n; i++)     
    {
	for (j = 0; j < n; j++)
	{
	    printf("%4d ",arr[i][j]);     //<----- printnig the elements as 2D array
	}
	printf("\n");
    }
}

