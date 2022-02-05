/*Documentation
Name: Anand N
Date: 04-11-2021
Description: To print all ascii characters
Sample i/p: 04_ascii.c
Sample o/p:
Dec	 Oct	 Hex	 Char
0	 000	 00	 Non printable
1	 001	 01	 Non printable
2	 002	 02	 Non printable
3	 003	 03	 Non printable
4	 004	 04	 Non printable
5	 005	 05	 Non printable
6	 006	 06	 Non printable   */

//Documentation
//WAP to print all ascii characters

#include<stdio.h>
int main()        
{
    int i;    //<----- decLared the int variables  

    printf ("Dec\t Oct\t Hex\t Char");   	//<--- printing the statement, used \t(tab) for mores spaces betweeen strings
    for ( i = 0; i <= 127; i++)    		//<---- iterating the all 128(0-127) ASCII codes over the for loop
    {
	if ( i >= 0 && i <= 31 || i == 127 )	//<---- validating the condition for non printable characters      
	{
	    printf ("\n %d\t %03o\t %02X\t Non printable",i,i,i);  //<--- 03/02 used to print 3 digits for octal & 2 digits for hexa representation 
	}
	if ( i == 32 )          //<---- validating the the conditio for space character
	{
	    printf ("\n %d\t %03o\t %02X\t %cSpace",i,i,i,i);
	}
	if ( i >= 33 && i <= 126)        //<----- validating the condition for all printable characters
	{
	    printf ("\n %d\t %03o\t %02X\t %c",i,i,i,i);
	}
    }
    printf ("\n");
    return 0;
}

