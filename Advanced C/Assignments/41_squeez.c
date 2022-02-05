/*Documentation
Name: Anand N
Date: 11-12-2021
Description:  Write an alternative version of squeeze(s1, s2) that deletes each character in 
s1 that matches any character in the string s2 
Sample i/p: 41_squeeze.c
Sample o/p:
Enter string-1: Hey hello welcome
Enter string-2: world
After squeeze string is: Hey he ecme

Do you want to continue?(Y/y): n   */

#include<stdio.h>
#include<string.h>
void squeeze(char *str1, char *str2);
int main()
{
    char ch;
    do
    {
	char str1[100];     //<---- declared string1 with size
	char str2[100];     //<---- declared the string2 with size

	printf("Enter string-1: ");
	scanf("%[^\n]%*c", str1);    //<---reads the string1 from user, for ignoring the new line to the next string used %*c

	printf("Enter string-2: ");
	scanf("%[^\n]", str2);   //<--- reads the string2 from user

	squeeze(str1, str2);      //<----- function calling for sring squeezing form str2 to str1
	printf("After squeeze string is: %s\n",str1);

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c%*c",&ch);                          //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;
}

void squeeze(char *str1, char *str2)     //<---- function definition for string squeeze
{
    int i, j, k=0;                      //<---- declared the int variables
    for(i = 0; str2[i] != '\0'; i++)    //<---- string2 iterating over the for looop
    {
	for(j = k = 0; str1[j] != '\0'; j++)  //<--- iterating string1 over the for loop, temp value k also iterating
	{
	    if(str1[j] != str2[i])   //<--- validating the condition for string1 characters not equal to the string2 characters
	    {
		str1[k++] = str1[j];  //<--- then asiging the string1 charcters to the temp variable
	    }
	}
	str1[k] = '\0';    ///<--- assigning the null character to the string1
    }
}

