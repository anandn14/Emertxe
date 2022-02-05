/*Documentation
Name: Anand N
Date: 02-11-2021
Descreption: Print sizes of all data types
Sample i/p: 05_sizeof.c
Sample o/p:
The size of int is: 4 bytes
The size of char: 1 byte 
The size of float is: 4 bytes 
The size of double is: 8 bytes 
The size of shor int is: 2 bytes 
The size of long int is: 8 bytes 
The size of long doble is: 16 bytes 
The size of long long int is: 8 bytes 
The size of unsigned int is: 4 bytes 
The size of unsigned char is: 1 byte 
The size of void is: 1 byte
*/

//Documentation
// To print sizes of all basic data types of C

#include<stdio.h>
int main()
{
    int i;              //<--- declared the int data type
    char ch;            //<--- declared the char data type
    float num;		//<--- declared the float data type
    double num2;	//<--- declared the dounle data type
    short int num3;	//<--- declared the short int data type
    long int num4;	//<--- declared the long int data type
    long double num5;	//<--- declared the long double data type
    long long int num6;	//<--- declared the long long int data type
    unsigned int num7;	//<--- declared the unsigned int data type
    unsigned char ch2;	//<--- declared the unsogned char data type
    void *a;		//<--- declared the voide pointer can point to anything *

    printf("The size of int is: %zu bytes\n",sizeof (int));	    		 //<---- printing the size of int data type
    printf("The size of char: %zu byte \n",sizeof (char));     			 //<---- Printing the value of char data type
    printf("The size of float is: %zu bytes \n",sizeof (float));	 	 //<---- printing the size of float data type
    printf("The size of double is: %zu bytes \n",sizeof (double));	   	 //<---- printing the size of double data type
    printf("The size of shor int is: %zu bytes \n",sizeof (short int));		 //<---- printing the size of short int data type
    printf("The size of long int is: %zu bytes \n",sizeof (long int));		 //<---- printing the size of long int data type
    printf("The size of long doble is: %zu bytes \n",sizeof (long double));	 //<---- printing the size of long double dat type 
    printf("The size of long long int is: %zu bytes \n",sizeof (long long int));      //<---- printing the size of long long int data type
    printf("The size of unsigned int is: %zu bytes \n",sizeof (unsigned int));	    //<---- printing the size of unsigned int data type
    printf("The size of unsigned char is: %zu byte \n",sizeof (unsigned char));    //<---- printing the size of unsogned char data type
    printf("The size of void is: %zu byte \n",sizeof (void));			 //<---- printing the size of void type
    return 0;
}
