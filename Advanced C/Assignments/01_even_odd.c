/*Documentation
Name: Anand N
Date: 28-10-2021
Descreption: Given number is odd or even and its signedness
Sample i/p: 01_even_odd.c
Sample o/p:  Enter the number: 2
2 is +ve Even number
Do you want to continue?(Y/y): y
Enter the number: -7
-7 is -ve Odd number
Do you want to continue?(Y/y): y
Enter the number: 20014525
Entered number is out of range: 20014525
Do you want to continue?(Y/y): y
Enter the number: 0
0 is neither odd or Even
Do you want to continue?(Y/y): n
*/

//Documentation

#include<stdio.h>
int main()        
{
    int i, num, res;   //<--- declared the  integer variables
    char ch;         //<---- declared the char variable

    do              //<-- do while loop used for continue the process
    {
	int range = 1, range1 = 1;     //<-- initialized the integers
	printf("Enter the number: ");   //<--- printing the statement
	scanf("%d",&num);     //<--- reading the number from user
	if ( num != 0 )    //<--- condition to check the entered number is zero or not
	{
	    for ( i = 0; i < 20; i++)   //<--- for loop to find out the entered number in the range of -2^20 to 2^20
	    {
		range = range * 2;     //<--- finding out product of the number
		range1 = range * -1;   //<---- if number is negatve then result will be negative
	    }
	    if ( num > 0 ) //<--- condition to check the Entered number is posivive or negative
	    {
		if ( num >= 1 && num <= range )    //<---- conditon to check the number in the range of 2^20 only
		{
		    res = (num / 2) * 2;    //<---- expression for finding out the number even or odd
		    if ( res != num )      //<---- condition to check the number is equal to result or not
		    {
			printf("%d is +ve Odd number\n",num);   //<--- printing the statement of number is not equal to result then its odd number
		    }
		    else
		    {
			printf("%d is +ve Even number\n",num);   //<--- printing the statement of number is equal to result then its even number
		    }
		}
		else  
		{
		    printf("Entered number is out of range: %d\n",num);  //<-- printig the statement if entered number not in the range
		}
	    }
	    else
	    {
		if ( num <= -1 && num >= range1 )   //<---- conditon to check the number in the range of -2^20 only
		{
		    res = (num / 2) * 2;     //<---- expression for finding out the number even or odd
		    if ( res != num )      //<---- condition to check the number is equal to result or not
		    {
			printf("%d is -ve Odd number\n",num);   //<--- printing the statement of number is not equal to result then its even number
		    }
		    else
		    {
			printf("%d is -ve Even number\n",num);      //<--- printing the statement of number is equal to result then its even number
		    }
		}
		else
		{
		    printf("Entered number is out of range: %d\n",num);     //<-- printig the statement if entered number not in the range
		}
	    }
	}
	else
	{
	    printf("0 is neither odd or Even\n");     //<--- Printing the statement if entered number is 0
	}

	printf("Do you want to continue?(Y/y): ");     //<---- Printing the statement for user continue or not
	scanf("\n %c",&ch);                           //<---- reading the user choice for continue process
    }while (ch == 'Y' || ch == 'y');                 //<---- assigined charactrers y & Y only for coice to continue

    return 0;
}

