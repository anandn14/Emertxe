/*Documentation
Name: Anand N
Date: 31-12-2021
Description: Print bits of float & double. Check IEEE std. 
Sample i/p: 31_fd_binary.c
Sample o/p:
Select the choice:
1. float
2. double
Enter the choice: 1
Enter the float value: 2.5
Sign 	Exponent	 	Mantissa
----------------------------------------------------------------
0 	1 0 0 0 0 0 0 0 	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 

Do you want to continue?(Y/y): y
Select the choice:
1. float
2. double
Enter the choice: 2
Enter the double value: 2.5
Sign 	Exponent	 	Mantissa
----------------------------------------------------------------
0 	1 0 0 0 0 0 0 0 0 0 0 	0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 

Do you want to continue?(Y/y): n    */

#include<stdio.h>
void float_binary(float *num);      //<---- function prototype for float binary 
void double_binary(double *num);   //<---- function prototype for double binary
void print_line();       	  //<------ Function prototype to printline 
int main()
{
    char ch;
    do
    {
	int choice;   //<---- declared the int variable
	float f_n;    //<----- declared the float variable
	double d_n;   //<----- declared the double variable

	printf("Select the choice:\n1. float\n2. double\nEnter the choice: ");
	scanf("%d", &choice);   //<---- reading the choice from user

	switch(choice)      //<---- validating the choice for performing the operation
	{
	    case 1:    //<---- for float type
		{
		    printf("Enter the float value: ");
		    scanf("%f",&f_n);        //<---- reading the flaot number fron user
		    printf("Sign \tExponent\t \tMantissa\n");
		    print_line();           //<---- function calling for printnig the -- lines
		    float_binary(&f_n); //<----- Function calling to print IEEE std of float value
		    printf("\n");
		}
		break;
	    case 2:    //<----- for double type
		{
		    printf("Enter the double value: ");
		    scanf("%lf",&d_n);
		    printf("Sign \tExponent\t \tMantissa\n");
		    print_line();
		    double_binary(&d_n); //<----- Function calling to print IEEE std of float value
		    printf("\n");
		}
		break;
	    default:
		printf("Enter valid choice\n");
	}
	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}

void float_binary(float *num)     //<---- function definition for float type
{
    int i;
    int *ptr = (int *)num;         //<----- initialized the int type pointer variable
    for (i = (8 * sizeof(int) - 1); i >= 0; i--)   //<----- iterating the loop for for printnig the number binary format
    {
	if ( i == 30 || i == 22)    //<----- validating the condition for i value equals to the 30 & 22 
	{
	    printf("\t");
	}

	((*ptr >> i) & 1 )? printf("1 "):printf("0 ");    //<---- number right shifted by i times then ANDed with 1
    }
}
void double_binary(double *num)       //<---- function definition for double type
{
    int i;
    long int *ptr = (long int *)num;     //<----- Type casting double number to long int
    for(i =(8 * sizeof(long int)- 1); i >= 0; i--) //<------ iterating the Loop to  print number binary format
    {
	if ( i == 62 || i == 51)
	{
	    printf("\t");
	}
	((*ptr >> i) & 1 )? printf("1 "):printf("0 ");  //<---- number right shifted by i times then ANDed with 1
    }
}
void print_line()  //<----- Function to print line
{
    for (int i = 0; i < 64; i++)
    {
	printf("-");
    }
    printf("\n");
}

