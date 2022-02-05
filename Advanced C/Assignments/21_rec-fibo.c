/*Documentation
Name: Anand N
Date: 28-11-2021
Description: WAP to generate fibbonacci numbers <= 'n' using recursions without using static keyword and global variables.
Sample i/p: 21_rec_fibbo_rev.c
Sample o/p:
Enter the n value: 7
fibbonacci series is: 0 1 1 2 3 5 
Do you want to continue?(Y/y): y
Enter the n value: -12
fibbonacci series is: 0 1 -1 2 -3 5 -8

Do you want to continue?(Y/y): n    */

#include<stdio.h>
int pos_rec(int, int, int, int);    //<---- function prototype for positive fiibbonacci series recursion
int neg_rec(int, int, int, int);    //<---- function prototype for negative fibbonacci series recusrion

int main()
{
    char ch;
    do              //<--- do-while loop for continue the prcess
    {
	int n, sum = 0, num1 = 0, num2 = 1;    //<---- declared the intvariables

	printf("Enter the n value: ");
	scanf("%d", &n);                    //<---- reading the value from useer
	printf("fibbonacci series is: ");
	if (n > 0)                          //<--- validating the condition for entered num is +ve or -ve
	    pos_rec(num1, num2, sum, n);    //<---- function calling for +ve series recusrion
	else
	    neg_rec(num1, num2, sum, n);   //<----- function calling for -ve series recusrion

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}

int pos_rec(int num1, int num2,int res,int num)    //<---- function definition for +ve fibbo series
{
    if (num1 <= num)             //<--- base condition for recursive function validating the condion
    {
	printf("%d ",num1); 
	res = num1 + num2;        //<---- adding the num1 and num2 then storing in the res variable
	num1 = num2;              //<--- assigning the num2 value to the num1
	num2 = res;              //<--- assigning the res value to the num2
	pos_rec(num1, num2, res, num);    //<---- function clling recursively
    }
}
int neg_rec(int num1, int num2,int res,int num)    //<---- function definition for -ve fibbo series
{
    if(num1 >= num)      //<--- validating the condition 
    {
	int n = num1 * -1;   //<---- expressuion for avoiding the negative number next generating value
	if(num <= n)            //<--- validating the condition for number is leesthan or equl to the generated series number
	    printf("%d ",num1);
	res = num1 - num2;     
	num1 = num2;
	num2 = res;
	neg_rec(num1, num2, res, num);   //<---- function calling recursively

    }
}
