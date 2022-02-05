/*Documentation
Name: Anand N
Date: 27-12-2021
Description:WAP to implement fragments using Array of Pointers (First Static Second Dynamic) 
Sample i/p: 37_fragment.c
Sample o/p:
Enter the no. of rows: 3
Enter the no. of col in row[0]: 4    
Enter the no. of col in row[1]: 3
Enter the no. of col in row[2]: 5

Enter 4 values for row[0]: 4 5 6 8
Enter 3 values for row[1]: 2 8 9
Enter 5 values for row[2]: 1 2 3 4 1

Before sorting:
4   5   6   8   5.75 
2   8   9   6.33 
1   2   3   4   1   2.2 

After sorting:
1   2   3   4   1   2.2 
4   5   6   8   5.75 
2   8   9   6.33 

Do you want to continue?(Y/y): n    */

#include<stdio.h>
#include<stdlib.h>
void print(int, float **, int *);      //<---- function prototpe for peinting the array
void fragment(int, float **, int *);   //<--- function prototype for fragmentation
int main()
{
    char ch;   

    do     //<--- do-while loop for continue the process
    {
	int r, i, j;      //<---- declared theint vriables
	float sum = 0, avg = 0;              //<--- initialized the float variables 

	printf("Enter the no. of rows: ");
	scanf("%d",&r);          //<---- reading the row size fro user

	float *arr[r];      //<---- declared the flaot array pointer type
	int col[r];         //<---- declared the int type array
	for (i = 0; i < r ; i++)    //<---- iterating the row size over the for loop for reading the column size
	{   
	    printf("Enter the no. of col in row[%d]: ",i);
	    scanf("%d",&col[i]);                           //<---- reading the column size from user
	    arr[i] = malloc((col[i] + 1)*sizeof(float));    //<---- allocating the memory for coumns dynamically
	}

	for (i = 0; i < r ; i++)  
	{   
	    if(arr[i] == NULL)    //<---- validating the condition for dynamically memory allocated or not
	    { 
		fprintf(stderr,"Unable to allocate the memory\n");
		return 1;
	    } 
	}
	printf("\n");
	for (i = 0; i < r ; i++)      //<---- iterating the row size over the for loop
	{
	    printf("Enter %d values for row[%d]: ",col[i],i);
	    for (j = 0; j < col[i]; j++)        //<----- iterating the column size over the for loop
	    {
		scanf("%g",&arr[i][j]);   //<---- reading the rray elements from user
		sum += arr[i][j];         //<--- calculating the sum of the each row elements
	    }
	    avg = sum / (col[i]);        //<---- calculating the average of the each row elements
	    arr[i][col[i]] = avg;        //<---- assigning the avarage value to the last column in each row
	    sum = 0;                     //<---- making sum 0 for each row sum calculation 
	}
	printf("\n");

	printf("Before sorting:\n");
	print(r,arr,col);           //<---- calling the function for printnig the 2D-array

	fragment(r,arr,col);       //<--- calling the function for fragmentation

	printf("\n"); 
	printf("After sorting:\n");
	print(r,arr,col);          //<---- calling the function for printnig the 2D-array

	for (i = 0; i < r ; i++)
	{
	    free(arr[i]);        //<---- frees the memery
	    arr[i] = NULL;       //<--- assgning the NULL to the array address
	}

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}

void print(int row, float **arr, int *col)     //<---- function definition for printing the 2-D array
{
    int i, j;
    for(i = 0; i < row; i++)
    {
	for(j = 0; j < (col[i] + 1);j++)
	{ 
	    printf("%-3.3g ",arr[i][j]); 
	}
	printf("\n");      //<---- printing the array elements in next line
    }
}

void fragment(int row, float **arr,int *col)     //<----- function definition for fragmentation
{
    int i, j, tmp = 0;        //<----- declared the int variables
    float *t;             //<---- decklared the flaot pointer temp varables

    for(i = 0; i < row; i++)       //<---- iterating the outer for loop for rowth size
    {
	for(j = i + 1; j < row; j++)   //<---- iterating the for loop for rowth size,assigned the j = i + 1 for every iteration
	{ 
	    if(arr[i][col[i]] > arr[j][col[j]]) //<-validating condition for 1D array avarage is greater than next 1D array avarage value 
	    {
		t = arr[i];          //<---- swapping the array rows
		arr[i] = arr[j];
		arr[j] = t;
		tmp = col[i];        //<---- swapping the array columns
		col[i] = col[j];
		col[j] = tmp;
	    }
	}
    }
}
