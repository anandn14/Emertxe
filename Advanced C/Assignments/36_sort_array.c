/*Documentation
Name: Anand N
Date: 09-12-2021
Description: Read n & n floats in a float array ’store’. Print the values in sorted order
without modifying or copying ’store’
Sample i/p: 36_sort_array.c
Sample o/p:
Enter the count of the elements need to store: 5
Enter the elements of array:
[0] --> 3.2
[1] --> -0.8
[2] --> 6.5
[3] --> -1.4
[4] --> 2.5
array after sorting: -1.4 -0.8 2.5 3.2 6.5 
Original Array: 3.2 -0.8 6.5 -1.4 2.5 

Do you want to continue?(Y/y): n      */

#include<stdio.h>
void sort_arr(float *arr,int n);   //<---- function prototype for sort array

int main()
{
    char ch;
    do
    {
	int i, n;        //<-- declared the int variables
	printf("Enter the count of the elements need to store: ");
	scanf("%d", &n);                         //<-- reading size of array size from user
	float arr[n];             //<---- declared the array type and its name
	printf("Enter the elements of array:\n");
	for(i = 0; i < n; ++i)                 //<--iterating the size of array over the for loop
	{
	    printf("[%d] --> ", i);        //<--- printing the index of array
	    scanf("%f", &arr[i]);        //<---- reading the array elements from the user
	}

	printf("array after sorting: ");
	sort_arr(arr,n);       //<---- function calling for sorting the array

	printf("\n");
	printf("Original Array: ");
	for (i = 0; i < n; i++)
	{
	    printf("%.1f ", arr[i]);    //<---- printing the original array
	}
	printf("\n");
	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;
}


void sort_arr(float *ptr,int n)
{
    int i,j;                    
    float large = ptr[0];    //<---declared the float varaibles
    float small = ptr[0]; 
    float temp = ptr[0];

    for (i = 0; i < n; i++)           //<--- iterating the array size over for loop
    {
	if ( ptr[i] > large)       //<---- validating the condition for laragest number from array
	{
	    large = ptr[i];      //<--- assigning the largest number to the variable large
	}
	if ( ptr[i] < small)    //<--- validating the condition for smallest number from the array
	{
	    small = ptr[i];    //<---- assigning the smallest number to the variable small
	}
    }
    for ( int i = 0 ; i < n ; i++ )         
    { 
	printf("%.1f ", small);     //<--- for printing the first smallest numaber   
	temp = large;               //<---- assigning the larger value to the temp variable
	for( int j = 0 ; j < n ; j++ )                      
	{
	    if(small < ptr[j] && ptr[j] < temp)     //<---- validating the condition for smallest value
		temp = ptr[j];      //<---- assigning the smallest value to the temp value
	}
	small = temp;               //<---assigning the smallest numbers to the variable small 
    }
}
