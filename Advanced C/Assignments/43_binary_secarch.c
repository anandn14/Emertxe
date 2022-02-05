/*Documentation
Name: Anand N
Date: 24-12-2021
Description: WAP to implement binary search for all basic datatypes. 
Sample i/p: 43_binary_search.c
Sample o/p:
Enter the size of array: 5
Select your choice:
1. int
2. char
3. short
4. float
5. double
Enter your choice: 1
Enter 5 elemnts of int type:
[0] -> 3
[1] -> 2
[2] -> 1
[3] -> 5
[4] -> 4
After sorting: 1 2 3 4 5 
Enter the key element to search: 4
Key element 4 is at position 3 of array

Do you want to continue?(Y/y): n   */

#include<stdio.h>
int binary_search_key(void *, void *, int, int);    //<--- function prototype for binary search 

int main()
{
    char ch;
    do       //<--- do-while loop for the continue the process
    {
	int n, choice;
	printf("Enter the size of array: ");
	scanf("%d",&n);   //<---- reading array size from user

	printf("Select your choice:\n1. int\n2. char\n3. short\n4. float\n5. double\nEnter your choice: ");
	scanf("%d", &choice);    //<----- reading the choice from user

	switch(choice)        //<----- validating the user choice for performimg the opearation
	{
	    case 1:       //<--- for int data type
		{
		    int i, j, res;     //<---- declared the variables

		    int arr[n];      //<---- declared the int array type
		    printf("Enter %d elemnts of int type:\n",n);

		    for (i = 0; i < n; i++)   //<---- iterating the array size over the for loop fro reading the elements
		    {
			printf("[%d] -> ",i);
			scanf("%d",&arr[i]);    //<---- reading the array elements from user
		    }    

		    for (i = 0; i < n; i++)   //<---- iterating the array elements outer & inner for loop for sorting the array
		    {   
			for (j = 0; j < n; j++)
			{
			    if(arr[j] > arr[i])   //<---- validating the condition for greater then
			    {
				int temp = arr[j];   //<---- assigning the temp variable to store the arr[j] value
				arr[j] = arr[i];     //<---- assigning the arr[j] to store the arr[i] value
				arr[i] = temp;       //<--- assigning the arr[i] to store the temp value
			    }
			}
		    }   
		    printf("After sorting: ");
		    for (i = 0; i < n; i++)     //<---- for loop for printing the sorted array
			printf("%d ",arr[i]);

		    int key;
		    printf("\nEnter the key element to search: ");
		    scanf("%d",&key);          //<---- reading the key element from the user
		    void *ptr = &key;        //<---- initializing the void poiter as key element address

		    res = binary_search_key(ptr, arr, n, choice);   //<---- function calling for int tyoe binary search
		    if (res != -1)                   //<--- validating the condition for return value is not equal to -1
			printf("Key element %d is at position %d of array\n",key, res);
		    else
			printf("Key element not found in array\n");
		}
		break;
	    case 2:        //<--- for char data type
		{
		    int i, j, res;

		    char arr[n];        //<---- declared the char type array
		    printf("Enter %d elemnts of char type:\n",n);
		    for (i = 0; i < n; i++)    //<---- for loop for reading the array elements
		    {
			printf("[%d] -> ",i);
			scanf("%*c%c",&arr[i]);    //<-- reading the array elements from user
		    }

		    for (i = 0; i < n; i++)   //<---- iterating the array elements over the outer & inner for loop for sorting the array
		    {   
			for (j = 0; j < n; j++)
			{
			    if( arr[j] > arr[i])   //<---- validating the condition for greater elements
			    {
				char temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			    }
			}
		    }   
		    printf("After sorting: ");
		    for (i = 0; i < n; i++)        //<---- for loop for printnig the sorted array
			printf("%c ",arr[i]);

		    char key;    
		    printf("\nEnter the key element to search: ");
		    scanf("%*c%c",&key);
		    void *ptr = &key;        //<----- declared the void pointer as key elemet

		    res = binary_search_key(ptr,arr, n, choice);   //<---- function calling for binary search of char type
		    if (res != -1)       //<---- validating the condition
			printf("Key element %c is at position %d of array\n",key, res);
		    else
			printf("Key element not found in array\n");
		}
		break;
	    case 3:      //<---- for short data type
		{
		    int i, j, res;

		    short arr[n];     //<---- declared the short data type
		    printf("Enter %d elemnts of short type:\n",n);
		    for (i = 0; i < n; i++)   //<---- for loop for reading the array elements
		    {
			printf("[%d] -> ",i);
			scanf("%hd",&arr[i]);   //<---- reading the array elements from the user
		    }

		    for (i = 0; i < n; i++)    //<---- iterating the array elements over the outer & inner for loop for sorting the array
		    {   
			for (j = 0; j < n; j++)
			{
			    if (arr[j] > arr[i])
			    {
				short temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			    }
			}
		    }   
		    printf("After sorting: ");  
		    for (i = 0; i < n; i++)   //<----- for loop for printing the sorted array
			printf("%hd ",arr[i]);  

		    short key; 
		    printf("\nEnter the key element to search: ");
		    scanf("%hd",&key);     //<---- reading the key element from user
		    void *ptr = &key;      //<--- declared the void type pointer

		    res = binary_search_key(ptr,arr, n, choice);   //<----- function calling for short type binar search
		    if (res != -1)
			printf("Key element %hd is at position %d of array\n",key, res);
		    else
			printf("Key element not found in array\n");
		}
		break;
	    case 4:      ///<--- for float data type
		{
		    int i, j, res;

		    float arr[n];    //<---- declared the flaot array type
		    printf("Enter %d elemnts of float type:\n",n);
		    for (i = 0; i < n; i++)    //<---- for loop for reading the array elements
		    {
			printf("[%d] -> ",i);
			scanf("%f",&arr[i]);   //<---- reading the array elements from user
		    }    

		    for (i = 0; i < n; i++) //<---- iterating the array elements over the outer & inner for loop for sorting the array
		    {   
			for (j = 0; j < n; j++)
			{
			    if (arr[j] > arr[i])
			    {
				float temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			    }
			}
		    }   
		    printf("After sorting: ");
		    for (i = 0; i < n; i++)     //<---- for loop for printing the sorted array
			printf("%g ",arr[i]);

		    float key;
		    printf("\nEnter the key element to search: ");
		    scanf("%f",&key);     
		    void *ptr = &key;     //,--- declared the void pointer

		    res = binary_search_key(ptr,arr, n, choice);   //<---- function calling for binary search for float type
		    if (res != -1)
			printf("Key element %g is at position %d of array\n",key, res);
		    else
			printf("Key element not found in array\n");
		}
		break;
	    case 5:       //<---- for double data type
		{
		    int i, j, res;

		    double arr[n];    //<---- declared the double type array
		    printf("Enter %d elemnts of double type:\n",n);
		    for (i = 0; i < n; i++)  //<---- for loop for reading the array elements
		    {
			printf("[%d] -> ",i);
			scanf("%lf",&arr[i]);    //<---- reading the array elements from user
		    }    

		    for (i = 0; i < n; i++)  //<---- iterating the array elements over the outer & inner for loop for sorting the array
		    {   
			for (j = 0; j < n; j++)
			{
			    if (arr[j] > arr[i])
			    {
				double temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			    }
			}
		    }   
		    printf("After sorting: ");
		    for (i = 0; i < n; i++)    //<---- for loop for printig thre sorted array elements
			printf("%g ",arr[i]);

		    double key;
		    printf("\nEnter the key element to search: ");
		    scanf("%lf",&key);
		    void *ptr = &key;   //<------ declared the void pointer

		    res = binary_search_key(ptr,arr, n, choice);    //<----- function calling for binary search for double type 
		    if (res != -1)
			printf("Key element %g is at position %d of array\n",key, res);
		    else
			printf("Key element not found in array\n");
		}
		break;
	    default:
		printf("Invalid chooice, Please enter valid choice");
	}

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                            //<----- reading the user choice for continue the process or not
    }while ( ch == 'Y' || ch == 'y' );                 //<----- validating condition of user choice

    return 0;
}


int binary_search_key(void *key, void *arr, int n, int option)   //<---- function definition for binary search
{
    int start = 0, mid = 0, end = n - 1;   //<--- initialized the int variables

    if (option == 1)    //<---- validating the option, here type casted the pointer and array as int type
    {
	while(start <= end)   //<---- iterating condition over while loop runs upto start encounters lessthan or equal to end
	{
	    mid = (start + end) / 2;    //<---- assigning the mid to the mid of the array index
	    if(*(int *)key == ((int *)arr)[mid])   //<---- validating the key element is equal to mid of the array
		return mid;                   //<--- returns the mid value

	    else if(*(int *)key > ((int *)arr)[mid]) //<--  validating the condition for key element greater than mid of the array element
		start = mid + 1;             //<---- assigning the start to mid element increase to 1

	    else if(*(int *)key < ((int *)arr)[mid])  //<-- validating the condition for key element lesser than mid of the array element
		end = mid - 1;             //<---- assigning the end to mid element decrease to 1
	}
	return -1;  //<---- if key element is not in the array returning the -1
    }
    if (option == 2)   //<--- validating the option, here type casted the pointer and array as char type 
    {
	while(start <= end)  ///<---- loop runs upto start encounters the leasser than or equal to the end
	{
	    mid = (start + end) / 2;
	    if(*(char *)key == ((char *)arr)[mid])
		return mid;             //<---- returning the mid value                

	    else if(*(char *)key > ((char *)arr)[mid])
		start = mid + 1;

	    else if(*(char *)key < ((char *)arr)[mid])
		end = mid - 1;
	}
	return -1;    //<---- if key element is not in the array returning the -1
    }
    if (option == 3)   //<----- validating the condition, here type casted the pointer and array as short type
    {
	while(start <= end)  //<---- loop runs upto start encounters the leasser than equal to end 
	{
	    mid =(start + end) / 2;
	    if(*(short *)key == ((short *)arr)[mid])
		return mid;    //<----- returning the mid value

	    else if(*(short *)key > ((short *)arr)[mid])
		start = mid + 1;

	    else if(*(short *)key < ((short *)arr)[mid])
		end = mid - 1;
	}
	return -1;      //<---- if key element is not in the array returning the -1
    }
    if (option == 4)    //<---- vaalidating the condition, here type casted the pointer and array as float type
    {
	while(start <= end)    //<---- loop runs upto start encounters the leasser than equal to end 
	{
	    mid =(start + end) / 2;
	    if(*(float *)key == ((float *)arr)[mid])
		return mid;        //<---- returning the mid vlaue

	    else if(*(float *)key > ((float *)arr)[mid])
		start = mid + 1;

	    else if(*(float *)key < ((float *)arr)[mid])
		end = mid - 1;
	}
	return -1;   //<---- if key element is not in the array returning the -1
    }
    if (option == 5)    //<---- vaalidating the condition, here type casted the pointer and array as double type
    {
	while(start <= end)    //<---- loop runs upto start encounters the leasser than equal to end 
	{
	    mid = (start + end) / 2;
	    if(*(double *)key == ((double *)arr)[mid])   
		return mid;     //<----- returning the mid value

	    else if(*(double *)key > ((double *)arr)[mid])
		start = mid + 1;

	    else if(*(double *)key < ((double *)arr)[mid])
		end = mid - 1;
	}
	return -1;     //<---- if key element is not in the array returning the -1
    }
}
