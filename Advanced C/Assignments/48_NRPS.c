/*Documentation
Name: Anand N
Date: 26-12-2021
Description: WAP to take n and k (1 <= k <= 10) as inputs. Generate consecutive NRPS of length n using k distinct character (1 <= k <= 9)
Sample i/p: 48_NRPS.c
Sample o/p:
Enter the no. of characters: 3
Enter the length of string: 9
Enter 3 distinct character: and
Possible NRPS is: andndadan

Do you want to continue?(Y/y): n    */

#include <stdio.h> 
#include <ctype.h> 
void nrps( char *, int *, int *);  //<---- function prototype for geb=nerating the NRPS 

int main()
{ 
    char ch;    //<---- declared the char variable
    do        //<---- do-while for continue the process
    {
	char arr[50];    //<---- declared the char type array
	int c = 0, n = 0, i, j, count = 0;     //<---- initialized the int variables
	printf("Enter the no. of characters: ");
	scanf("%d", &c);            //<----- reading the no. of characters from user
	printf("Enter the length of string: ");
	scanf("%d", &n);           //<----- reading length of string from user

	if (c >= 1 && c <= 10)     //<---- validating the condition for no. of charcters to be in the limit or not
	{
	    printf("Enter %d distinct character: ", c);
	    for (i = 0; i < c; i++)            //<---- for loop for reading the characters            
	    {
		scanf("\n%c", &arr[i]);        //<---- reading the charcters from user

		if (isalpha(arr[i]));  //<---- validatig the condition entered charcters are alpha only
		else
		{
		    count++;    //<---- if not increase the count then break the loop
		    break;
		}
	    }
	    if (count == 0)    //<--- validating the condition count is 0
	    {
		for (i = 0; i < c; i++)    //<---- iterating the characters over the 2 for loops
		{
		    for (j = i + 1; j < c; j++)
		    {
			if (arr[i] == arr[j])   //<---- validating the entered characters are distinct or not
			    count++;
		    }
		    if (count != 0)   //<---- validating the condition
			break;
		}
	    }

	    if( count == 0 )           //<-----validating the condition count is 0 or not
		nrps(arr, &c, &n );   //<----- function calling for generate the NRPS
	    else
		printf("NRPS not possible, Enter only distinct alpha characters\n");
	}
	else
	    printf("Invalid input, no. of char should be in limit of 1<char<10\n");

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process
    }while ( ch == 'Y' || ch == 'y' );          //<----- validating condition of user choice

    return 0;
}

void nrps (char *arr, int *ch, int *len)     ///<----function definition for generating the NRPS
{
    int i = 0, j, k;     //<---- declared the int variables 
    char temp;
    printf("Possible NRPS is: "); 
    for(j = 0; i < *len; j++)      //<---- for loop for printing the characters
    {
	printf("%c",arr[j]);
	if( j == *ch -1)  //<---- validate the condition, if j reached to no.of chars then manipulating array
	{
	    for(k = 0; k < *ch - 1; k++)   //<-----for loop for manipulating array
	    {
		temp = arr[k+1];
		arr[k+1] = arr[k];
		arr[k] = temp;
	    }
	    j = -1;            //<---- setting j value to -1 then it will increment to 1
	}
	else if( i == *ch * *ch )    //<---- validating the condition, if the i reached to value(ch * ch) then manipulate array 
	{
	    for(k = 0; k < *ch - 1; k++)    //<---- for loop for generating one more total combination
	    {
		temp = arr[k+1];
		arr[k+1] = arr[k];
		arr[k] = temp;
	    }
	}
	i++;
    }
    printf("\n");
}

