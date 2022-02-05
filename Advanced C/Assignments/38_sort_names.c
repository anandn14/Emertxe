/*Documentation
Name: Anand N
Date: 13-01-2022
Description: Read n & n person names of maxlen 32. Sort and print the names
Sample i/p: 38_sort_names.c
Sample o/p: 
Enter the count of names: 5
[0]-->Bengaluru
[1]-->Mumbai
[2]-->Delhi
[3]-->Hyderabad     
[4]-->Chennai

After sorting the names:
[0]--> Bengaluru
[1]--> Chennai
[2]--> Delhi
[3]--> Hyderabad
[4]--> Mumbai

Do you want to continue?(Y/y): n    */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort_names(int, int, char **);  //<----function prototype for sort-names

int main()
{
    char ch;

    do     //<----- do-while loop used for continue the process or not
    {
	int i, n = 0;

	printf("Enter the count of names: ");
	scanf("%d", &n);     //<---- reading the size form the user
	char **arr;

	arr = (char **)malloc(n * sizeof(char *));    //<---- Dynamically alloacted the memory for the rows

	for ( i = 0; i < n; i++)       //<---- iterating the rows over the for loop
	{
	    arr[i] = malloc (32 * sizeof(char ));    //<---- assigned the col size 32 max length for each row

	    printf("[%d]-->",i); 
	    scanf("%*c%[^\n]",arr[i]);      //<---- reading the array from user
	}

	if(arr == NULL)      //<----- validating the condition for the addres of array is NULL or not
	{
	    fprintf(stderr,"Unable to allocated memory\n");
	    return 1;
	}

	for ( i = 0; i < n; i++)       //<---- iterating the rows over the for loop
	    if((strlen(arr[i]) > 32 ))
	    {
		printf("Enter max length 32 characters only\n");
	    }
	    else
	    {

		sort_names(n, 32, arr);     //<---- function calling for the sorting the names

		printf("\nAfter sorting the names:\n");
		for ( i = 0; i < n; i++)
		{
		    printf("[%d]--> %s\n",i,arr[i]);
		}

		if(arr != NULL)     //<--- validating the condition for address of array is not equal to null
		{
		    free(arr);     //<----- frees the allocated memory  
		    arr = NULL;    //<----- assigning the memory address to NULL
		}
	    }

	printf("\nDo you want to continue(Y/y): ");
	scanf("\n%c", &ch);
    }while (ch == 'Y'|| ch == 'y');

    return 0;
}

void sort_names(int row, int col, char **arr)   //<--- function definition for the sorting the names
{
    int i, j, k = 0;    //<----- declared the int variables
    char *temp;   //<---- declaed the temp variable

    for (i = 0; i < row; i++)
    {
	for (j = i + 1; j < row; j++)
	{
	    if(arr[i][k] == arr[j][k])    //<---- validating string comparing the one string to next string of characters
		k++;                      //<---- if condition becomes true then incease the k
	    if (arr[i][k] > arr[j][k])    //<--- validating the condition for first string is greater than next string for swapping
	    {
		temp = arr[i];          //<---- first array elements asssigned to temp varaible
		arr[i] = arr[j];        //<----- next array elements assigned to the first array address
		arr[j] = temp;         //<---- temp array elemets assigned to the next array address
	    }
	}
    }
}

