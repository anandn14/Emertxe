/*Documentation
Name: Anand N
Date: 19-12-2021
Description: Variance calculation with static arrays & with dynamic arrays 
Sample i/p: 35_variance.c
Sample o/p:
Enter the no. of elements: 5
Select the option:
1. static allocation
2. Dynamic allocation
Enter your option: 1
Eneter the array elements:
[0] --> 5
[1] --> 4
[2] --> 2
[3] --> 3
[4] --> 1

input	D=x-mean	D^2
5	 2		4
4	 1		1
2	-1		1
3	 0		0
1	-2		4
Sum = 15		D^2_Sum = 10
Variance is: 2

Do you want to continue?(Y/y): n    */

#include<stdio.h>
#include<stdlib.h>
void static_allocation (int *ptr ,int size);  //<--- function prototype for static alloaction
void dynamic_allocation(int size);     //<---- function prototype for dynamicc alloaction
int main()
{
    char ch; 
    do      //<--- do-while loop for the continue the process
    {
	int num, option;     //<---- declared the int variabke

	printf("Enter the no. of elements: ");
	scanf("%d",&num);   //<---- reading the number from user

	int arr[num];    //<--- declared the array name with size

	printf("Select the option:\n1. static allocation\n2. Dynamic allocation\nEnter your option: ");
	scanf("%d", &option);    //<---- reading the option from user

	switch(option)  //<---- switching the option for user selected option
	{
	    case 1:     //<---- for static allocation
		{
		    static_allocation(arr,num);    //<-----function calling for static allocation
		    break;  
		}
	    case 2:
		dynamic_allocation(num);          //<--- function calling for dynamic allocation
		break;
	    default:
		printf("Enter the valid option");
	}
	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}
void static_allocation (int *ptr ,int size)    //<---- function definition for static allocation
{
    int sum = 0, mean = 0, d, sqr, sum_sqr = 0, var;  //<----initailized the variables
    printf("Eneter the array elements:\n");
    for ( int i=0; i < size; i++)    //<----- iterarting the for loop for storing the array elements
    {
	printf("[%d] --> ",i);     
	scanf("%d",&ptr[i]);        //<---- reading the array elements from user
	sum = sum + ptr[i];         //<---- expression for summing the each array elemets
    }

    mean = sum / size;                  //<---- expression for mean calculation
    printf("\ninput\tD=x-mean\tD^2\n");

    for(int i = 0; i < size; i++)    //<---- itearaqting the for loop for prnitng the each elemnts imput & output
    {
	d = ptr[i] - mean;       //<---- expression for finding the differemce of enetered number with the mean value
	sqr = d * d;             //<---- expression for calculatig the square of the difference
	sum_sqr = sum_sqr + sqr;  //<---- expresiion for finding the sum of the square numbers
	printf("%d\t%2d\t\t%d\n",ptr[i], d, sqr );
    }
    printf("Sum = %d\t\tD^2_Sum = %d\n",sum,sum_sqr);
    var = sum_sqr / size;          //<---- calculating the variance of elements
    printf("Variance is: %d\n",var); 
}

void dynamic_allocation(int size)    //<---- function definition for dynamic memeory alloaction
{
    int sum = 0, mean = 0, d, sqr, sum_sqr = 0, var; //<---- initialized the int variables
    int *ptr;
    ptr = calloc(size, sizeof(size));         //<--- dynamic memory allocate array creating using calloc

    if (ptr == NULL)        //<----- validating the conditionf for adrress is null or not
    {
	printf("memory not allocated\n");
    }
    else
    {
	printf("Eneter the array elements:\n");
	for ( int i = 0; i < size; i++)   //<---- iterating the for loop for storing the arra elements
	{
	    printf("[%d] --> ",i);
	    scanf("%d",&ptr[i]);        //<----reading array elements from user
	    sum = sum + ptr[i];         //<---- expression for the finding the sum of the elements     
	}
	mean = sum / size;                     //<----expression for calculating thr mean
	printf("\nx(input)\tD=x-mean\tD^2\n");

	for(int i = 0; i < size; i++)   //<---- iterating the for loopfor printnig the outputs results
	{
	    d = ptr[i] - mean;     //<---- expression for finding the difference between elemets and mean
	    sqr = d * d;            //<---- expression for the finding the square of the difference numbers
	    sum_sqr = sum_sqr + sqr;  //<---- expression for the sum of the square numbers
	    printf("%d\t\t%2d\t\t%d\n",ptr[i], d, sqr );
	}
	printf("Sum = %d\t\t D^2_Sum = %d\n",sum,sum_sqr);
	var = sum_sqr / size;            //<---- expression for findning the variance of the elements
	printf("Variance is: %d\n",var);

	free (ptr);             //<---- free the allocated memeory 
	ptr = NULL;             //<---- pointer that hold the address is set to NULL  
    }
}
