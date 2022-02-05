/*Documentation
Name: Anand N
Date: 28-11-2021
Description: Implement your own c-type library  
Sample i/p: 13_c-type_lib.c
Sample o/p:
Enter a character: %
Select any option:
1-isalpha
2-isalnum
3-isgraph
4-isdigit
Enter your option:3
The character '%' is the graph

Do you want to continue?(Y/y): y 
Enter a character: A 
Select any option:
1-isalpha
2-isalnum
3-isgraph
4-isdigit
Enter your option:4
The character 'A' is not the digit

Do you want to continue?(Y/y): n    */

#include<stdio.h>
int my_is_alpha(unsigned char);    //<----function prototype for my_is_alpha library
int my_is_alnum(char);            //<----function prototype for my_is_alnum library
int my_is_graph(char);           //<---function prototype for my_is_graph libarary
int my_is_digit(char);          //<---function prototype for my_is_digit library

int main()
{
    char choice;    //<----initializing choice as chracter variable
    do
    {
	int option, res1, res2, res3, res4;               //<---initializing option as integer variable
	char ch;        //<----initializing ch as character variable
	printf("Enter a character: ");
	scanf("\n%c", &ch);                 //<----reading the character from the user
	printf("Select any option:\n1-isalpha\n2-isalnum\n3-isgraph\n4-isdigit\nEnter your option:");
	scanf("%d",&option);                //<---reading the option from the user

	switch(option)                            
	{
	    case 1:
		res1 = my_is_alpha(ch);           //<----function calling for my_is_alpha
		if(res1)                                  
		    printf("The character '%c' is an alpha character\n",ch);  
		else
		    printf("The character '%c' is not an alpha character\n",ch);
		break;
	    case 2:
		res2 = my_is_alnum(ch);           //<----function calling for my_is_alnum
		if(res2)
		    printf("The character '%c' is an alnum character\n",ch);
		else
		    printf("The character '%c' is not an alnum character\n",ch);
		break;
	    case 3:
		res3 = my_is_graph(ch);       //<----- function calling my_is_graph
		if(res3)
		    printf("The character '%c' is the graph\n",ch);
		else
		    printf("The character '%c' is not the graph",ch);
		break;
	    case 4:
		res4 = my_is_digit(ch);      //<-----function calling my_is_digit
		if(res4)
		    printf("The character '%c' is the digit\n",ch);
		else
		    printf("The character '%c' is not the digit\n",ch);
		break;
	    default:
		printf("\nEnter only option fro above menu");

	}
	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&choice);                          //<----- reading the user choice for continue the process or not
    }while (choice == 'Y' || choice == 'y');                 //<----- validating condition of user choice
    return 0;
}


int my_is_alpha(unsigned char ch)     //<---function definition for my_is_alpha library
{
    return (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ? 1 : 0;  //<---returning & validating character is the lowercase and upper case alphabet
}
int my_is_alnum(char ch)             //<---function definition for my_is_alnum library
{
    return (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57) ? 1 : 0; //<---returing & validating character is alphabet or a number
}
int my_is_graph(char ch)        //<----function definition for is_graph libarary
{
    return (ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126) ? 1 : 0; //<--returning & validating the entered character is printable charcter or not
}
int my_is_digit(char ch)        //<-----function definition for my_is_digit library
{
    return (ch >= 48 && ch <= 57) ? 1 : 0;  //<---returning & validating the character is digit or not
}
