/*Documentation
Name: Anand N
Date: 12-12-2021
Description: WAF for pre and post increment and passing int pointer as their parameter  
Sample i/p: 20_pre-post_increment.c
Sample o/p:
Enter the num: 3
Select the operation:
1.Pre-increment
2.Post increment
choice: 1
After pre increment ret = 4 num = 4

Do you want to continue?(Y/y): y
Enter the num: 6
Select the operation:
1.Pre-increment
2.Post increment
choice: 2
After post increment ret = 6 num = 7

Do you want to continue?(Y/y): n   */

#include <stdio.h>      
int pre_increment(unsigned int *);    //<-----function prototype for pre increment
int post_increment(unsigned int *);   //<--- function prototype for post increment

int main()
{
    char ch;     //<---- declared the char variable
    do
    {
	int ret, num, choice;    //<---- declared the int variables

	printf("Enter the num: ");
	scanf("%d",&num);            //<--- readig the number from user

	printf("Select the operation:\n1.Pre-increment\n2.Post increment\nchoice: ");   
	scanf("%d",&choice);          //<----reading the choice from user

	switch(choice)             //<----- selecting the user choice
	{
	    case 1:
		ret = pre_increment(&num);     //<---- function calling for pre increment operation
		printf("After pre increment ret = %d num = %d\n", ret, num);
		break;
	    case 2:
		ret = post_increment(&num);   //<--- function calling for post increment operation
		printf("After post increment ret = %d num = %d\n", ret, num);
		break;
	    default:
		printf("Please Eneter valid options only");
	}

	printf ("\nDo you want to continue?(Y/y): ");    
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;
}

int pre_increment(unsigned int *n)     //<----function definition for pre increment operation
{
    unsigned int mask = 1;    //<---- assigned the mask value
    while (*n & mask)         //<---- iterating the number ANDing with the mask
    {
	//*n = *n & (~mask);   //<---- number Anding with the compliment of mask
	*n = *n ^ mask;   //<---- number Anding with the compliment of mask
	mask = (mask<<1);    //<--- generating the mask value
    }
    *n = *n | mask;     //<---- number Oring with the mask
    return *n;          //<---- returning the n value
}
int post_increment(unsigned int *n)    //<----- function definition for post increment
{
    unsigned int mask = 1;           
    while (*n & mask)
    {
	*n = *n & (~mask);
	mask = (mask<<1);
    }
    *n = *n | mask;
    return *n - 1;                    //<---- returning the n - 1 value
}
