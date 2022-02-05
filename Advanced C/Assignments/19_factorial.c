/*Documentation
Name: Anand N
Date: 29-11-2021
Description: WAP to find factorial for given number using recursive method and without using any other function than main function  
Sample i/p: 19_factorial.c
Sample o/p:
Enter the value of N: 3
factorial is: 6

Do you want to continue?(Y/y): y
Enter the value of N: 5
factorial is: 120

Do you want to continue?(Y/y): y
Enter the value of N: -5
Invalid number,Enter positive number only

Do you want to continue?(Y/y): n    */

#include<stdio.h>
int main()
{
    char choice;           //<--- declared the char variable
    static int n;         //<---- declraed n as the static int variable
    static int fact;      //<------ declared the fact as static variable

    if(n == 0 && fact == 0)    //<--- validating the condition of n and fact are to be 0
    {      
	printf("Enter the value of N: ");
	scanf(" %d", &n);                //<---- reading the n from the user
	fact=1;                 //<---initialize fact with value 1
	choice='y';       //<----- intialize the choice as y        
    }
    if (n < 0) 
    {   

	printf("Invalid number,Enter positive number only\n");
	return 1;   
    }   
    if( n > 0)       //<---- validating the conditon for enterd number is not equal to 0
    { 
	fact *= n;   //<--- -multiplying fact with the n value
	n--;        //<---- decrementing the n value
	main();    //<---- calling main function
    }
    else
    {
	printf("factorial is: %d\n",fact);         
	fact=0;                                      //<---- initializing fact  here with 0
	printf("\nDo you want to continue?(Y/y): ");     
	scanf("\n%c", &choice );                      //<-----reading the choice from the user
	if( choice == 'y' || choice == 'Y' )     //<----- validating the condition of choice
	    main();                               //<----- calling main function
    }
    return 0;
}

