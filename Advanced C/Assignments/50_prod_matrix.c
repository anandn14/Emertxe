/*Documentation
Name: Anand N
Date: 30-12-2021
Description: WAP to find the product of given matrix
Sample i/p: 50_prod_matrix.c
Sample o/p:
Enter the no. of rows: 2
Enter the no. of columns: 2
Enter values for 2 x 2 mattrix:
1 2
1 2

Entered Matrix is:
   1   2
   1   2

Transpose of given matrix is:
   1   1
   2   2

Product of given matrix is:
   5   5
   5   5

Do you want to continue?(Y/y): n   */

#include<stdio.h>
#include<stdlib.h>
void transpose_matrix(int **, int, int, int **); //<---- function prototype for transpose a matrix
void product_matrix(int **, int, int, int **, int **); //<----function prototype for multiplication of matrices
int main()
{
    char ch;
    do
    {
	int row = 0, col = 0, i, j, k;   //<---- declaring the int variables 
	int **arr = NULL, **t_arr = NULL, **res_arr = NULL;    //<----- declared the 2D array

	printf("Enter the no. of rows: ");
	scanf("%d", &row);       //<----reading the row size from user

	printf("Enter the no. of columns: ");
	scanf("%d", &col);       //<----- reading the column size from user

	if( row <= 0 || col <= 0)   //<----- validating the condition for entered row & col shoud be +ve integers
	    printf("Enter positive values only\n");
	else
	{
	    /* dyanallcally allocatinting the memory for the array rows*/
	    arr = (int **) malloc(row * sizeof(int *));       
	    t_arr = (int **) malloc(row * sizeof(int *));     
	    res_arr = (int **) malloc(row * sizeof(int *));  
	    /*iterating the columns for the over the for loop for allocating the memory */
	    for (i = 0; i < col; i++)         //<---- iterating the columns for the over the for loop for allocating the memory
	    {
		arr[i] = (int *) malloc(col * sizeof(int));    
		t_arr[i] = (int *) malloc(col * sizeof(int));
		res_arr[i] = (int *) malloc(col * sizeof(int));
	    }
	    if ( arr == NULL || t_arr == NULL || res_arr == NULL)    //<--- validating the condition for memory allocated or mot
	    {
		fprintf(stderr,"Unable to allocate the memory");
		return 1;
	    }
	    printf("Enter values for %d x %d mattrix:\n",row,col);
	    for (i = 0;  i < row; i++)
	    {
		for (j = 0; j < col; j++)
		{
		    scanf("%d",&arr[i][j]);      //<---- reading the array elements from user
		}
	    }

	    printf("\nEntered Matrix is:\n");
	    for (i = 0;  i < row; i++)
	    {
		for (j = 0; j < col; j++)
		{
		    printf("%4d ",arr[i][j]);      //<---- printing the array elements
		}
		printf("\n");
	    }

	    printf("\nTranspose of given matrix is:\n");
	    transpose_matrix(arr,row,col,t_arr); //<----- function calling for transpose a matrix
	    for (i = 0;  i < col; i++)
	    {
		for (j = 0; j < row; j++)
		{
		    printf("%4d ",t_arr[i][j]);      //<---- printing the array trnspose array elements
		}
		printf("\n");
	    }

	    printf("\nProduct of given matrix is:\n");
	    product_matrix(arr,row,col,t_arr,res_arr);   //<--- function calling for multiplication of matrix
	    for (i = 0;  i < row; i++)
	    {
		for (j = 0; j < row; j++)
		{
		    printf("%4d ",res_arr[i][j]);      //<---- printing the product of array elements
		}
		printf("\n");
	    }

	    /* frees the allocated memory*/
	    free(arr);
	    free(t_arr);
	    free(res_arr);
	}
	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c%*c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}

void transpose_matrix(int **arr,int row,int col,int **t_arr)   //<--- function definition for transpose a matrix
{
    for (int i = 0 ; i < row; i++)
    {   
	for (int j = 0; j < col; j++)
	{
	    t_arr[j][i] = arr[i][j];     //<----- transpose of matirx
	}
    }   
}
void product_matrix(int **arr,int row,int col,int **t_arr,int **res_arr) //<---- function definition for multiplication of matrices
{
    for (int i = 0; i < row; i++ )
    {   
	for (int j = 0; j < col; j++)
	{
	    for (int k = 0; k < col; k++)
	    {
		res_arr[i][j] += arr[i][k] * t_arr[k][j];	//<----- multiplication of matrix
	    }
	}
    }
}
