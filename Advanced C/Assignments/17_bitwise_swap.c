/*Documentation
Name: Anand N
Date: 28-11-2021
Description: To write a program to swap two variables by using pass by reference method  
Sample i/p: 17_bitwise_swape.c
Sample o/p:
Enter a num1: 5
Enter a num2: 10
After swapping the numbers:
num1 = 10
num2 = 5

Do you want to continue?(Y/y): n    */

#include<stdio.h>
void bitwise_swap(int *, int *);   //<--- function prototype for bitwise swapping

int main()
{
    char ch;    //<--- initializing the char data type
    do
    {
	int num1, num2;    //<---- initializing the int value

	printf("Enter a num1: ");
	scanf("%d",&num1);   //<---- reading the number1 from user

	printf("Enter a num2: ");
	scanf("%d",&num2);   //<---- reading the number2 from useer
	
	bitwise_swap(&num1, &num2);   //<---- function calling for swapping the numbers by passing address of numbers
	printf("After swapping the numbers:\nnum1 = %d\nnum2 = %d\n",num1,num2);

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}

void bitwise_swap(int *n1, int *n2)    //<--- function definition forbi twise swap
{
    *n1 = *n1 ^ *n2;              //<----bitwise XORing the numbers then assigning to the *n1 
    *n2 = *n1 ^ *n2;             //<----bitwise XORing the numbers then assigning to the *n2
    *n1 = *n1 ^ *n2;            //<----bitwise XORing the numbers then assigning to the *n1
}

