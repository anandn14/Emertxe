/*Documentation
Name: Anand N
Date: 27-11-2021
Description: Readan integer & a number n, circular right & left shift by n
Sample i/p: 16_bits_shifts.c
Sample o/p:
Enter the number:15
Enter the n value:3
1.circular right shift
2.circular left shift
Enter the option:1
The binary format of number:  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 1 1 1 1 
After circular right shifting by 3
The binary format of number:  1 1 1 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 0  0 0 0 0 0 0 0 1 

Do you want continue(y/Y)? y
Enter the number:-12
Enter the n value:4
1.circular right shift
2.circular left shift
Enter the option:2
The Binary format of num:  1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1  1 1 1 1 0 1 0 0 
After circular left shifting by 4
The binary format of number:  1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1  0 1 0 0 1 1 1 1

Do you want to continue?(Y/y): n       */

#include<stdio.h>
int circular_right(unsigned int,int);    //<----function prototypr for circular right shift
int circular_left(unsigned int,int);    //<----function prototype for circular left shift
void print_bits(int, int);              //<----function prototype for print_bits
int main()
{
    char ch;            //<---initializing character variable
    do
    {
	int num, n, option;                //<---initializing integer variables
	printf("Enter the number:");
	scanf("%d",&num);               //<---reading the number from user
	printf("Enter the n value:");
	scanf("%d",&n);                     //<---reading the n value from the user
	printf("1.circular right shift\n2.circular left shift\nEnter the option:");
	scanf("%d",&option);              //<----reading the option from user
	int result;
	switch(option)
	{
	    case 1:
		result=circular_right(num,n);              //<---function call for circular right shift
		printf("The binary format of number: ");
		print_bits(num,32);                               //<----function call for printing bits
		printf("After circular right shifting by %d\n",n);
		printf("The binary format of number: ");
		print_bits(result,32);                         //<-----function call for prnting the bits of the result
		break;
	    case 2:
		result=circular_left(num,n);             //<---function call for circular left shift
		printf("The Binary format of num: ");
		print_bits(num,32);                                //<----function call for printing bits
		printf("After circular left shifting by %d\n",n);
		printf("The binary format of number: ");
		print_bits(result,32);                          //<----function call for printing the bits of result
		break;
	}
	printf("\nDo you want continue(y/Y)? ");                    
	scanf("\n %c",&ch);                         //<----reading choice from the user
    }while(ch == 'y' || ch == 'Y');
    return 0;
}

int circular_right(unsigned int num,int n)    //<-----function definition for circular right shift
{
    return num >> n | num << (32-n);  //<--- returning the number right shift by n bits then ORing with the left shift of number - n bits
}

int circular_left(unsigned int num,int n)   //<---function definition for circular left shift
{
    return num << n | num >> (32-n); //<--- returning the number left shift by n bits then ORing with the right shift of number - n bits
}

void print_bits(int num, int n)        //<----function definition for print_bits
{
    for (int i = n-1;i >= 0;i--)    //<---iteration the bits over the for loop
    { 
	if ( (i + 1) % 8 == 0)	  //<----validating the condition for each 8 bits in a byte
	    printf(" ");
	(num >> i & 1)?printf("1 "):printf("0 ");  //<---using the ternary printing the bits
    }   
    printf("\n");
}

