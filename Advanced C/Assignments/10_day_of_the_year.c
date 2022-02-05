/*Documentation
Name: Anand N
Date: 10-11-2021
Descreption: Find which day of the year 
Sample i/p: 10_day_of_the_year.c
Sample o/p: 
Enter the Nth day of the year:9
Choose first day:
1.Sunday
2.Monday
3.Tuesday
4.Wednesday
5.Thursday
6.Friday
7.Saturday
Enter the option to set the first day: 4
The 9th day is Thursday

Do you want to continue:(y/Y) y
Enter the Nth day of the year:10
Choose first day:
1.Sunday
2.Monday
3.Tuesday
4.Wednesday
5.Thursday
6.Friday
7.Saturday
Enter the option to set the first day: 8
Error:Invalid input the starting day should be > 0 & <= 7

Do you want to continue:(y/Y) y
Enter the Nth day of the year:0
Error:Invalid input the Nth day should be > 0 & <= 365

Do you want to continue:(y/Y) y
Enter the Nth day of the year:366
Error:Invalid input the Nth day should be > 0 & <= 365

Do you want to continue:(y/Y) n       */

#include<stdio.h>
int main()
{
    char ch;    //<---- declared the char variable

    do     //<---- used do-while for continue the process
    {
	int num = 0, day = 0, rem = 0, res = 0;    //<---- declared the int variables
	printf ("Enter the Nth day of the year:");  
	scanf ("%d", &num);      //<---- read the number from user

	if ( num > 0 && num <= 365 )   //<--- validating the condition for entered number to be in between 1 to 365
	{ 
	    printf ("Choose first day:\n1.Sunday\n2.Monday\n3.Tuesday\n4.Wednesday\n5.Thursday\n6.Friday\n7.Saturday\nEnter the option to set the first day: ");      //<---- printing the menu for users option 
	    scanf ("%d", &day);   //<---- read the starting day from the user

	    if ( day > 0 && day <= 7)    //<--- validating the condition for selected day to be in between 1 to 7
	    {
		res = (num + day - 1);   //<---- expression for calculating the day
		rem = (res % 7);        //<----- expression to finding the day
		switch (rem)            //<---- will shows the Nth day
		{
		    case 1:
			printf ("The %dth day is Sunday\n",num);
			break;
		    case 2:
			printf ("The %dth day is Monday\n",num);
			break;
		    case 3:
			printf ("The %dth day is Tuesday\n",num);
			break;
		    case 4:
			printf ("The %dth day is Wednesday",num);
			break;
		    case 5:
			printf ("The %dth day is Thursday\n",num);
			break;
		    case 6:
			printf ("The %dth day is Friday\n",num);
			break;
		    case 0:
			printf ("The %dth day is Saturday\n",num);
			break;
		}
	    }
	    else
	    {
		printf ("Error:Invalid input the starting day should be > 0 & <= 7\n");
	    }
	}
	else
	{
	    printf ("Error:Invalid input the Nth day should be > 0 & <= 365\n");
	}

	printf ("\nDo you want to continue:(y/Y) ");   
	scanf ("\n %c", &ch);      //<----- reading the user choice for yes or no

    }while ( ch == 'y' || ch == 'Y' );    //<---- validating the condition of user choice yes
    return 0;
}


