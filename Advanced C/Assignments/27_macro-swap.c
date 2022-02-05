/*Documentation
Name: Anand N
Date: 10-01-2022
Description: To define a macro swap (t, x, y) that interchanges two arguments of type t
Sample i/p: 27_macro_swap.c
Sample o/p:
Select your option:
1. int
2. char
3. short
4. float
5. double
6. string
Enter your option: 6
Enter the string1: Hello
Enter the string2: World

After swapping
string1 is: World
string2 is: Hello

Do you want to continue?(Y/y): n    */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* macrp definition for swapping the 2 argumens */
#define SWAP(s,a,b)	\
{                  	\
    s temp = a;    	\
    a = b;          	\
    b = temp;        	\
}
int main()
{
    char ch;    //<---- declared the char variable
    do
    {
	int option;

	printf("Select your option:\n1. int\n2. char\n3. short\n4. float\n5. double\n6. string\nEnter your option: ");
	scanf("%d", &option);   //<---- reading the option from user

	switch(option)       //<---- valiadating the condition for option
	{
	    case 1:       //<----- for int data type
		{
		    int num1, num2;       //<---- declared the int variables
		    printf("Enter the num1: ");
		    scanf("%d",&num1);    
		    printf("Enter the num2: ");
		    scanf("%d",&num2);

		    SWAP(int, num1, num2);    //<---- macro calling for swapping the int data type arguements

		    printf("\nAfter swapping\n");
		    printf("num1 is: %d\nnum2 is: %d\n",num1, num2);
		}
		break;
	    case 2:     //<----- for char data type
		{
		    char ch1, ch2;      //<--- declared the char variables
		    printf("Enter the character1: ");
		    scanf("%*c%c",&ch1);
		    printf("Enter the character2: ");
		    scanf("%*c%c",&ch2);

		    SWAP(char, ch1, ch2);    //<---- macro calling for swapping the char data types arguments

		    printf("\nAfter swapping\n");
		    printf("character1 is: %c\ncharacter2 is: %c\n",ch1, ch2);
		}
		break;
	    case 3:      //<----- for short data type
		{
		    short n1, n2;      //<---- declared the short data variables
		    printf("Enter the num1: ");
		    scanf("%hd",&n1);
		    printf("Enter the num2: ");
		    scanf("%hd",&n2);

		    SWAP(short, n1, n2);    //<---- macro calling for swappig the short data types arguments

		    printf("\nAfter swapping\n");
		    printf("num1 is: %hd\nnum2 is: %hd\n",n1, n2);
		}
		break;
	    case 4:     //<------ for float data type
		{
		    float n1, n2;   //<---- declared the float variavbles
		    printf("Enter the float type num1: ");
		    scanf("%f",&n1);
		    printf("Enter the float type num2: ");
		    scanf("%f",&n2);

		    SWAP(float, n1, n2);   //<---- macro calling for swapping the float data type arguments

		    printf("\nAfter swapping\n");
		    printf("float num1 is: %f\nfloat num2 is: %f\n",n1, n2);
		}
		break;
	    case 5:     //<----- for double data type
		{
		    double n1, n2;       //<----- declared the double variables
		    printf("Enter the double type num1: ");
		    scanf("%lf",&n1);
		    printf("Enter the double type num2: ");
		    scanf("%lf",&n2);

		    SWAP(double, n1, n2);    //<----- macro calling for swapping the double data type arguments

		    printf("\nAfter swapping\n");
		    printf("double num1 is: %lf\ndouble num2 is: %lf\n",n1, n2);
		}
		break;
	    case 6:       //<---- for dstring data type
		{
		    char *str1, *str2;     //<---- declared the string variables

		    str1 = malloc(20 * sizeof(char));   //<---- Dynamically allocated the memory for str1
		    str2 = malloc(20 * sizeof(char));   //<---- Dynamically allocated the memory for str2

		    printf("Enter the string1: ");
		    scanf("%s",str1);
		    printf("Enter the string2: ");
		    scanf("%s",str2);

		    SWAP(char *, str1, str2);       //<---- macro calling for swapping the string arguments

		    printf("\nAfter swapping\n");
		    printf("string1 is: %s\nstring2 is: %s\n",str1, str2);

		    free(str1);     //<----- frees the memory of str1
		    free(str2);	    //<---- frees the memory of str2
		}
		break;
	    default:
		printf("Entter valid option\n");
	}
	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice
    return 0;
}
