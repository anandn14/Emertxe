/*Documentation
Name: Anand N
Date: 16-11-2021
Description:i To print bits of signed and unsigend types for given number & check for 2'scompliment 
Sample i/p: 12_print-bitis.c
Sample o/p:
Enter the num:10
 10 -->  0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0   0 0 0 0 1 0 1 0 
-10 -->  1 1 1 1 1 1 1 1   1 1 1 1 1 1 1 1   1 1 1 1 1 1 1 1   1 1 1 1 0 1 1 0 

Do you want to continue?(Y/y): y
Enter the num:12
 12 -->  0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0   0 0 0 0 1 1 0 0 
-12 -->  1 1 1 1 1 1 1 1   1 1 1 1 1 1 1 1   1 1 1 1 1 1 1 1   1 1 1 1 0 1 0 0 

Do you want to continue?(Y/y): n       */

#include<stdio.h>
int main()
{
    char ch;   //<---- declared the char variable
    do         //<-- do-while loop for continue option
    {
	int i, num, res=0;   //<---- declared the int variable

	printf ("Enter the num:");    
	scanf("%d",&num);    //<----- reading the number from user

	// for printing the positive number bits
	printf (" %d -->",num);   //<---- printing the +ve number
	for ( i = 31; i >= 0; i--)   //<---- number iterating over the for loop
	{
	    if( (i+1) % 8 == 0)     //<---- validating the condition for each 8 bits in a byte
		printf("  ");       //<---- printing the space after every 1 byte 
	    (num & (1 << i)) ? printf("1 ") : printf("0 ");   //<--validating & printing,condition is number is ANDed with masking of number for every iteration 
	}
	printf("\n");

	// for priniting the same number in -ve number of bits-2's compliment of number
	res = ~num + 1;     //<---- ~ compliments the number then adding to the number 1 (2's compliment)
	printf ("%d -->",-num);   //<---- printing thr number in -ve
	for ( i = 31; i >= 0; i--)     //<--- itarating the same -ve number over the for loop
	{
	    if( (i+1) % 8 == 0)    //<---- validating the condition for each 8 bits in a byte
		printf("  ");
	    (res & (1 << i)) ? printf("1 ") : printf("0 ");   //<--validating & printing,condition is number is ANDed with masking of number for every iteration
	}
	printf("\n");

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n %c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}    

