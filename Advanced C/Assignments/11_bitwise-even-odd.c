/*Documentation
Name: Anand N
Date: 17-11-2021
Descreption: To check a given number is even or odd and it's sign using bitwise operator
Sample i/p: 11_bitwise-even-odd.c
Sample o/p:
Enter the num:12
12 is positive even number

Do you want to continue?(Y/y): y
Enter the num:-13 
-13 is negative odd number

Do you want to continue?(Y/y): y
Enter the num:1048577
Entered number is out of range

Do you want to continue?(Y/y): y
Enter the num:0
0 is neither odd nor negative even

Do you want to continue?(Y/y): n  */

#include<stdio.h>
int main()
{
    char ch;     //<--- declare the char variable
    int range = 0, range1 = 0;   //<--- declared the int variables
    range  = 1 << 20;            //<---- expression for +ve range
    range1 = range * -1;         //<---- expression for -ve range 

    do     //<--- used do-while for continur the process
    {
	int num;       //<-- declare the int variable
	printf("Enter the num:");   
	scanf("%d",&num);   //<--- readint the num from user

	if (num != 0)    //<--- valadating thr condition for entered number is 0 or not
	{
	    if ( num >= range1 && num <= range) 
	    {
		if ( (num >> 31) & 01 == 1)    //<--- valiadating the condition for number sign bit 1 or 0
		{
		    printf("%d is negative ",num);
		}
		else
		{
		    printf("%d is positive ",num);
		}
		if ( num & 1 == 1)	//<--- validatng the condition for LSB bit is 1 or 0
		{
		    printf("odd number\n");
		}
		else
		{
		    printf("even number\n");
		}
	    }
	    else
		printf("Entered number is out of range\n");
	}
	else
	    printf("0 is neither odd nor even number\n");

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}

