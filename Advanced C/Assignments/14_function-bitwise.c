/*Documentation
Name: Anand N
Date: 23-11-2021
Description: Implement the mentioned bitwise functions  
Sample i/p: 14_function_bitwise.c
Sample o/p:
Select the bit operation from Menu:
1.get_n_bits
2.replace_nbits
3.get_nbits_from_pos
4.replace_nbits_ffrom_pos
5.toggle_bits_from_pos
6.print_bits
Enter your choice: 4
Enter num: 7
Enter value: 3
Enter n bits: 1
Enter position: 2
Binary format for 7 => 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 
Binary format for 3 => 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 
replace 1 bits from 3 value => 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 
Value after replacing 1 bits from 2 position is: 4

Do you want to continue?(Y/y): n    */

#include<stdio.h>
int get_nbit(int, int);               //<---function prototype for get n bits
int replace_nbit(int, int, int);       //<---function prototype for replace n bits
int get_nbits_from_pos(int, int, int);  //<--- function prototype for get n bits from position
int replace_nbits_from_pos(int, int, int, int);  //<--- function prototype for replace n bits from position
int toggle_nbits(int, int, int);   //<--- function prototype for togglen bits
int print_nbits(unsigned int, int);   //<--- function prototype for ptinting n bits
int main()
{
    char ch;    //<-- declared the char variable
    do         
    {
	int choice, num, n, val, pos, res; //<--- declred the int variables

	printf("Select the bit operation from Menu:\n1.get_n_bits\n2.replace_nbits\n3.get_nbits_from_pos\n4.replace_nbits_ffrom_pos\n5.toggle_bits_from_pos\n6.print_bits\nEnter your choice: "); //<--- menu dispaly for user options
	scanf("%d",&choice);   //<--- reading the user option

	switch(choice)   //<--- validating the condition of user choices option
	{
	    case 1:                   //<---- for get n bits
		printf("Enter num: ");
		scanf("%d",&num);
		printf("Enter n bits: ");
		scanf("%d",&n);
		printf("Binary format for %d => ", num);
		for ( int i = 31; i >= 0; i--)      //<--- iterating the number over for loop
		{
		    (num & 1 << i) ? printf("1 ") : printf("0 ");  //<---- number printing in the binary format
		}
		printf("\n%d bits from LSB => ",n);
		res = get_nbit(num, n);               //<---- function calling for get n bits
		for (int i = 31; i >= 0; i-- )
		{
		    res & (1 << i) ? printf("1 ") : printf("0 ");   //<---- result printing in binary format
		}
		printf("\nValue after getting %d bits is: %d\n", n, res);   //<--- printing in the int value of result
		break;
	    case 2:                       //<---for repalce n bits
		printf("Enter num: ");
		scanf("%d",&num);
		printf("Enter value: ");
		scanf("%d",&val);
		printf("Enter n bits: ");
		scanf("%d",&n);
		printf("Binary format for %d => ",num);
		for ( int i = 31; i >= 0; i-- )
		{
		    num & (1 << i) ? printf("1 ") : printf("0 ");  //<---- number printing in binary format
		}
		printf("\nreplace %d bits from %d value => ", n, val);
		res = replace_nbit(num, val, n);           //<---- function calling for replace n bit
		for (int i = 31; i >= 0; i-- )
		{
		    res & (1 << i) ? printf("1 ") : printf("0 ");   //<---- result printing in the binary format
		}
		printf("\nValue after replacing %d bits is: %d\n", n, res);
		break;

	    case 3:                   //<---for get n bits from position
		printf("Enter num: ");
		scanf("%d",&num);
		printf("Enter position: ");
		scanf("%d",&pos);
		printf("Enter n bits: ");
		scanf("%d",&n);
		if ( pos > n )  //<--- validating the condition for postion should be greater than n bits
		{
		    printf("Binary format for %d => ", num);
		    for ( int i = 31; i >= 0; i-- )
		    {
			num & (1 << i) ? printf("1 ") : printf("0 ");  //<--- number printing in the binary format
		    }
		    printf("\n%d bits from %d pos => ", n, pos);
		    res = get_nbits_from_pos(num, pos, n);   //<--- function calling for  get n bits from position
		    for (int i = 31; i >= 0; i-- )
		    {
			res & (1 << i) ? printf("1 ") : printf("0 "); //<--- result printing in the binary format
		    }
		    printf("\nValue after get %d bits from %d position is: %d\n",n, pos, res);
		}
		else
		{
		    printf("Position should be greater than 'n'\n");
		}
		break;
	    case 4:                    //<--- for replace n bits from position
		printf("Enter num: ");
		scanf("%d",&num);
		printf("Enter value: ");
		scanf("%d",&val);
		printf("Enter n bits: ");
		scanf("%d",&n);
		printf("Enter position: ");
		scanf("%d",&pos);
		if ( pos > n )    //<--- validating the condition for position shouuld be greater than n bits
		{
		    printf("Binary format for %d => ", num);
		    for ( int i = 31; i >= 0; i-- )
		    {
			num & (1 << i) ? printf("1 ") : printf("0 ");  //<--- number prinint in the binary format
		    }
		    printf("\nBinary format for %d => ", val);
		    for ( int i = 31; i >= 0; i-- )
		    {
			val & (1 << i) ? printf("1 ") : printf("0 ");  //<--- value printing in the binary format
		    }
		    printf("\nreplace %d bits from %d value => ", n, val);
		    res = replace_nbits_from_pos(num, val, n, pos);   //<--function calling for replace n bits from position
		    for (int i = 31; i >= 0; i-- )
		    {
			res & (1 << i) ? printf("1 ") : printf("0 ");  //<----- result prontnig in the binary format
		    }
		    printf("\nValue after replacing %d bits from %d position is: %d\n",n, pos, res);
		}
		else
		{
		    printf("Position should be greater than 'n'\n");
		}
		break;
	    case 5:                   //<---- for toggle n bits
		printf("Enter num: ");
		scanf("%d",&num);
		printf("Enter position: ");
		scanf("%d",&pos);
		printf("Enter n bits: ");
		scanf("%d",&n);
		if ( pos > n )
		{
		    printf("Binary format for %d => ", num);
		    for ( int i = 31; i >= 0; i-- )
		    { 
			num & (1 << i) ? printf("1 ") : printf("0 ");  //<---- number printing in the binary format
		    }
		    printf("\n%d bits from %d position => ", n, pos);
		    res = toggle_nbits(num, pos, n);    //<--- function calling for toggle n bits    
		    for (int i = 31; i >= 0; i--) 
		    {
			res & (1 << i) ? printf("1 ") : printf("0 ");   //<--- result printing in the binary format
		    }
		    printf("\nValue after toggling %d bits from %d position is: %d\n", n, pos, res);
		}
		else
		{
		    printf("Position should be greater than 'n'\n");
		}
		break;
	    case 6:                     //<---- for printing n bits
		printf("Enter num: ");
		scanf("%d",&num);
		printf("Enter n bits: ");
		scanf("%d",&n);
		printf("\nlast %d bits is: ", n);
		print_nbits(num, n);    //<--- function calling for printing the n bits
		break;
	    default:
		printf("Enter correct choice");
		break;
	}
	printf ("\nDo you want to continue?(Y/y): ");    
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;

}

int get_nbit(int num, int n)   //<---- function definition for get n bits
{
    return num & ~(-1 << n);   //<--- number ANDing with the mask
}

int replace_nbit(int num, int val, int n)  //<--- function definition for replace n bits
{
    return (num & (-1 << n) | (val & ~(-1 << n))); //<--- number & value ANDing with the mask then ORing of both results
}
int get_nbits_from_pos(int num, int pos, int n) //<-- function definition for get n bits from position
{
    return (num & (~(-1 << n)) << pos - n + 1) >> pos - n + 1; //<-- num ANDing with mask of left shift of position of bits then final result will be right shift of position of bits, for taking the result from LSB
}
int replace_nbits_from_pos(int num, int val, int n,int pos)  //<--- function definition for replace n bits from position
{
    int mask;
    mask = ~(-1 << n);   //<--- genarating the mask
    return (num & (mask << pos - n + 1) & ((val & ~(-1 << n)) << pos - n + 1));  //<--- number & value ANDing with the mask of left shift of position of bits, then ANDing of both results
}
int toggle_nbits(int num, int pos,int n)  //<--function definition for toggle of n bits
{
    return num ^ (~(-1 << n) << pos - n + 1);   //<--- number XORing with the mask of left shift of position of bits
}
int print_nbits(unsigned int num, int n)   //<----function definition for printing n bits
{
    int i;
    for (int i = n-1; i >= 0; i-- )
    {
	(num & (1 << i )) ? printf("1 ") : printf("0 ");   //<--- printing n bits of number only
    }
}
