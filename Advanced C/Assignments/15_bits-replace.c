/*Documentation
Name: Anand N
Date: 27-11-2021
Description: Read int val, read 0 <= a <= b <= 31. read an int int n, put the (b-a+1) LSB's of n into i[b:a]  
Sample i/p: 15_bits_replace.c
Sample o/p:
Eneter the num:15
Eneter the value:20
Eneter the value of a:3
Eneter the value of b:5
The binary form of num:  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 1 1 1 1 
The binary form of val:  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 1 0 1 0 0 
Updated binary form of val(60): 0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 1 1 1 1 0 0 

Do you want to continue?(Y/y): y
Eneter the num:11
Eneter the value:174
Eneter the value of a:5
Eneter the value of b:3
value should be greater than a and <= 31

Do you want to continue?(Y/y): n    */


#include<stdio.h>
int replace_nbits_from_pos(int, int, int, int);  //<---- function prototype for replace_nbits from position
void print_bits(int, int);      //<---prototype for printing the bits

int main()
{
    char ch;    //<--- declared the char variable

    do        
    {
	int num, n=32, a, b, c, val, ans;  //<---- initialized the int variables
	printf("Eneter the num:");
	scanf("%d",&num);            //<---- reading the num from user

	printf("Eneter the value:");
	scanf("%d",&val);           //<--- reading the value from user

	printf("Eneter the value of a:");
	scanf("%d",&a);           //<--- reading the a value from user

	printf("Eneter the value of b:");
	scanf("%d",&b);          //<---- reading the b value from user

	if( a >= 0 && a <= 31 )      //<---- validating the condition for a should be in the range 0 to 31
	{
	    if( b >= a && b <= 31 )  //<---- validating the condition for a should be in the range 0 to 31
	    {
		printf("The binary form of num: ");
		print_bits(num, n);     //<---- function call for printing the binary form of num

		printf("The binary form of val: ");
		print_bits(val, n);   //<---- function call for printing the binary form of val

		c = b - a + 1;        //<---- declared the c value 
		ans = replace_nbits_from_pos(val, c, b, num);   //<--- function call for replace nbits from position and stored in ans var
		printf("Updated binary form of val(%d):", ans);  
		print_bits(ans, n);    //<---- function call for printing the binary form of updated
	    }
	    else
	    {
		printf("value should be greater than a and <= 31 \n");
	    }
	}
	else
	{
	    printf("Value of a exceded,value should be to 0 to 31");
	}
	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;
}

void print_bits(int num, int n)      //<--- function definition of print bits
{
    int i;
    for ( i = n - 1; i >= 0; i--)   //<---- number iterating over the for loop
    {
	if( (i+1) % 8 == 0)     //<---- validating the condition for each 8 bits in a byte
	    printf(" ");
	(num & (1 << i)) ? printf("1 ") : printf("0 ");   //<--- printing the bits in binaray form used ternary operator
    }
    printf("\n");
}

int replace_nbits_from_pos(int val, int c, int b,int num)  //<--- function definition for replace nbits from position
{
    return ((num & (1 << c) - 1) << b - c + 1) | (val & ~(((1 << c) - 1) << b - c + 1)) ;  //<--- returning the num ANDing with the masking of number then ORing with the value that ANDed with masking of value
}
