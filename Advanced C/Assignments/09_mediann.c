/*Documentation
Name: Anand N
Date: 18-11-2021
Description: WAP to find the median of two unsorted arrays
Sample i/p: 09_median.c
Sample o/p:
	Enter the size of array1: 5
	Enter the elements of array1: 1 2 4 5 3
	after sorting: 1 2 3 4 5 
	median1 = 3 
	Enter the size of array2: 4 
	Enter the elements of array2: 2 4 1 3
	after sorting : 1 2 3 4 
	median2 = 2.5 
	median of both arrays: 2.75 
	Do you want to continue?(Y/y): n     */

#include<stdio.h>
int main()
{
	char ch;
	do
	{
		int n, res, i, j ,t = 0, t1 = 0;   //<-- declared the int variables
		float med1, med2, median;          //<--- declared the float variables
		printf("Enter the size of array1: ");
		scanf("%d", &n);                         //<-- reading size of array1 from user

		if ( n > 0 && n < 11)       //<---- validating the condition for array is in the range of 1 - 10
		{
			int A1[n];             //<---- declaraed the array type and its name
			printf("Enter the elements of array1: ");
			for(i = 0; i < n; ++i)                 //<--iterating the size of array over the for loop
				scanf("%d", &A1[i]);        //<---- reading the array elements from the user

			for (i = 0; i < n; i++)               //<--- iterating the array size over the outer for loop i
			{
				for(j = i + 1; j < n; j++ )       //<-- iterating the i loop elements over the inner j loop
				{
					if(A1[i] > A1[j])     //<--- validating the condition for i greater than j for ascending sorting of numbers
					{
						t = A1[i];         //<---array i elements are assigning to temporary value t
						A1[i] = A1[j];     //<-- array j elements assigning to  the array i
						A1[j] = t;         //<-- t elements are assigning to t for the purpose of swapping elements
					}
				}
			}	
			printf("after sorting: ");
			for(i = 0; i < n; i++)
			{
				printf("%d ", A1[i]);  
			}	
			printf("\n");
			if(n % 2 == 0)        //<--- expression for finding the entered array is odd 0r even by reminder
			{
				med1 = ((float) A1[(n) / 2 - 1] + A1[n / 2]) / 2;  //<-- expression for the finding the median of even size of array1
				printf("median1 = %g ",med1);
			}
			else
			{
				med1 = A1[(n) / 2];    //<---- expression for the finding the median of odd size of array1
				printf("median1 = %g ",med1);
			}
			printf("\n");
		}
		else
		{
			printf("Invalid array size,enter 1 < n < 11\n");
		}
		printf("\n");
		printf("Enter the size of array2: ");
		scanf("%d", &n);                         //<---reading size of array2 from user
		if ( n > 0 && n < 11)
		{
			int A2[n];
			printf("Enter the elements of array2: ");
			for(i = 0; i < n; ++i)                //<--iterating the size of array over the for loop
				scanf("%d", &A2[i]);           //--- reading the array2 elements from the user

			for (i = 0; i < n; i++)             //<--- iterating the array size over the outer for loop i
			{
				for(j = i + 1; j < n; j++ )       ///<--- iterating the i loop elements over the inner for loop j 
				{
					if(A2[i] > A2[j])   //<--- validating the condition for i greater than j for ascending sorting of numbers
					{
						t1 = A2[i];         //<---array i elements are assigning to temporary value t
						A2[i] = A2[j];    //<-- array j elements assigning to the array i
						A2[j] = t1;       //<-- t elements are assigning to t for the purpose of swapping element
					}
				}
			}	
			printf("after sorting : ");
			for(i = 0; i < n; i++)
				printf("%d ", A2[i]);    
			printf("\n");
			if(n % 2 == 0)     //<--- expression for finding the entered array is odd 0r even by reminder
			{
				med2 = ((float) A2[(n) / 2 - 1] + A2[n / 2]) / 2;   //<-- expression for the finding the  even size of arra2
				printf("median2 = %g ",med2);
			}
			else
			{
				med2 = A2[(n) / 2];           //<---- expression for the finding median of odd size of array2
				printf("median2 = %g ",med2);
				printf("median2 = %g ",med2);
			}
			printf("\n");
			median = (float) (med1 + med2) / 2;           //<--- expression for the finding the both array median
			printf("median of both arrays: %g \n",median);
		}
		else
		{
			printf("Invalid array size,enter 1 < n < 11\n");
		}
		printf ("\nDo you want to continue?(Y/y): ");       
		scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
	}while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

	return 0;
}
