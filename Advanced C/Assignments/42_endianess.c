/*Documentation
Name: Anand N
Date: 16-12-2021
Description: WAP to check your processor endianess
Sample i/p: 42_endianess.c
Sample o/p:
Enter the number: 1025
Little endian system

Do you want to continue?(Y/y): y
Enter the number: 0
Little endian system

Do you want to continue?(Y/y): n    */

#include<stdio.h>

int main()
{
    char ch;
    do                 //<--- do-while for continue the process
    {
	int num;                  

	printf("Enter the number: ");
	scanf("%x",&num);               //<--- reading the number from user

	int *iptr = &num;           //<---- initialized the int pointer
	char *cptr = (char *)&num;    //<---- initialized the char pointer

	if (*cptr == *(char *)iptr)  //<---- valiadating the condition for character byte size equal to the int size by making typecasting
	    printf("Little endian system\n");
	else
	    printf("Big endian system\n");

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process
    }while ( ch == 'Y' || ch == 'y' );          //<----- validating condition of user choice

    return 0;
}
