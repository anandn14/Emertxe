/*Documentation
Name: Anand N
Date: 20-01-2021
Description: WAP to demote the type of given float number to integer using bitwise operators and bitfields.
Sample i/p: 29_demotes_int.c
Sample o/p:
Enter a float value: 2.35 
demoted int value: 2.000000

Do you want to continue?(Y/y): y
Enter a float value: -3.66
demoted int value: -3.000000

Do you want to continue?(Y/y): y
Enter a float value: 0.3
demoted int value: 0.000000

Do you want to continue?(Y/y): n    */

#include<stdio.h>

/* Union definition */
union
{
    float f;

    struct
    {
	unsigned int mant :23;
	unsigned int expo :8;
	unsigned char sign :1;
    }bits;
}num;

int main()
{
    char ch;           //<---- declared the char variable 
    int f1;            //<----- declared the int variable
    
    do                 
    {
	printf("Enter a float value: ");
	scanf("%f", &num.f );             //<----- reading the float valure from user 

	if (num.bits.expo >= 127)    //<---- validating the condition for exponent part of number is >= 127
	{
	    /* Print demoted float value */
	    f1 = num.bits.expo - 127;  
	    num.bits.mant &= (~((1 << (23 - f1)) - 1));
	    printf("demoted int value: %f\n", num.f);
	}
	else
	{
	    /* print demoted float value */
	    f1 = 127 - num.bits.expo;
	    num.bits.sign &= 0;
	    num.bits.expo &= 0;
	    num.bits.mant &= 0;
	    printf("demoted int value: %f\n", num.f);
	}

	printf ("\nDo you want to continue?(Y/y): ");    
	scanf ("\n%c",&ch);                      //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );           //<----- validating condition of user choice

    return 0;
}
