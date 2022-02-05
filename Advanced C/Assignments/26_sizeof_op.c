/*Documentation
Name: Anand N
Date: 08-01-2022
Description: To define a macro SIZEOF(x), where x is a variable, without using sizeof operator
Sample i/p: 26_size_op.c
Sample o/p:
Size of int	: 4 bytes
Size of char	: 1 byte
Size of float	: 4 bytes
Size of double	: 8 bytes
Size of unsigned int: 4 bytes
Size of long int: 8 bytes
Size of short	: 2 bytes      */

#include<stdio.h>
#include<stdlib.h>

#define SIZE(x) (char *)(&x + 1) - (char *)(&x)  //<--- defining the macro to type casted the address

int main()
{
    /* declatred the data types*/
    int num;
    char ch;
    float num1;
    double num2;
    unsigned int num3;
    long int num4;
    short num5;

    /* printing the sizeof the data types*/
    printf("Size of int\t: %lu bytes\n",SIZE(num));          //<--- calling the mcaro for int type 
    printf("Size of char\t: %lu byte\n",SIZE(ch));          //<---- calling the macro for char type
    printf("Size of float\t: %lu bytes\n",SIZE(num1));     //<--- calling the macro for float type
    printf("Size of double\t: %lu bytes\n",SIZE(num2));    //<---- calling the macro for double type
    printf("Size of unsigned int: %lu bytes\n",SIZE(num3)); //<---- calling the macro for unsigned int
    printf("Size of long int: %lu bytes\n",SIZE(num4));    //<---- calling the macro for long int type
    printf("Size of short\t: %lu bytes\n",SIZE(num5));    //<---- calling the ,acro for short type
}
