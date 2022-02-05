/*Documentation
Name: Anand N
Date: 21-12-2021
Description: Implement calc_mean for all data types
Sample i/p: 44_mean_calc.c
Sample o/p:
elect the choice:
1. int
2. short
3. float
4. double
Enter your choice: 1
Enter the size of array: 5
Enter the array elements:
[0] --> 1
[1] --> 2
[2] --> 3
[3] --> 4
[4] --> 5
mean value is: 3.00

Do you want to continue?(Y/y): n    */

#include<stdio.h>
float calc_mean(int, void *, int);  //<--- function prototype for calculation of mean 
int main()
{
    char ch;   //<---- declared the char variable
    do        //<----- do-while loop for continue the process
    {
	int num, choice;  //<----declared the int variables
	float ret;       //<---- declard the float variable

	printf("Select the choice:\n1. int\n2. short\n3. float\n4. double\nEnter your choice: ");
	scanf("%d",&choice);   //<---- reading the choice from user

	switch(choice)    //<---- validating the user choice
	{
	    case 1:      //<---- for int datatype
		{
		    printf("Enter the size of array: ");
		    scanf("%d",&num);   //<---- reading the size of the array from user
		    int arr[num];       //<---- declared the int type aaray
		    printf("Enter the array elements:\n");
		    for(int i = 0; i < num; i++)  //<---- iterating the size over the for loop for reading the array elements
		    {
			printf("[%d] --> ", i);    //<--- printing the array index
			scanf("%d",&arr[i]);     //<---- reading the elements form user
		    }
		    ret = calc_mean(choice,arr,num);   //<---- function caling for the calculating the mean value
		    printf("mean value is: %.2f\n",ret);
		}
		break;
	    case 2:     //<---- for short datatype
		{
		    printf("Enter the size of array: ");
		    scanf("%d",&num);
		    short arr[num];                   //<---- declared the shortshort type array
		    printf("Enter the array elementsi:\n");
		    for(int i = 0; i < num; i++)
		    {
			printf("[%d] --> ", i);
			scanf("%hd",&arr[i]);
		    }
		    ret = calc_mean(choice,arr,num);    //<---- function callig for calculating mean value
		    printf("mean value is: %.2f\n",ret);
		}
		break;
	    case 3:     //<----- for flaot datatype
		{
		    printf("Enter the size of array: ");
		    scanf("%d",&num);
		    float arr[num];          //<----- declared the float type array
		    printf("Enter the array elements:\n");
		    for(int i = 0; i < num; i++)
		    {
			printf("[%d] --> ", i);
			scanf("%f",&arr[i]);
		    }
		    ret = calc_mean(choice,arr,num);    //<---- function calling for calculating the mean value
		    printf("mean value is: %.2f\n",ret);
		}
		break;
	    case 4:    //<---- for double datatype
		{
		    printf("Enter the size of array: ");
		    scanf("%d",&num);
		    double arr[num];    //<---- declared the double type array
		    printf("Enter the array elements:\n");
		    for(int i = 0; i < num; i++)
		    {
			printf("[%d] --> ", i);
			scanf("%lf",&arr[i]);
		    }
		    ret = calc_mean(choice,arr,num);    //<---- function calling for calculating the mean value
		    printf("mean value is: %.2f\n",ret);
		}
		break;
	    default:
		printf("Eneter only valid numbers");
	}

	printf("\nDo you want to continue(y/Y): "); 
	scanf("\n%c",&ch);                  //<----- reading the user choice from user
    }while( ch == 'y' || ch == 'Y');        //<--- validating the user choice for continue the process

    return 0;
}

float calc_mean(int option, void *ptr,int n)     //<---- function definitioan for calculation of mean
{
    float mean = 0, sum = 0;     //<---- initialized the flaot variables

    if(option == 1)     //<---- validating the condition for eneterd option equal to 1
    {
	for (int i = 0; i < n; i++)
	{
	    sum = sum + *((int *)ptr+i);      //<--- adding the array elements, and typecasted as int type
	}
	mean =  sum / n;              //<----- expression fr the calculatig the mean value
	return mean;           //<--- returning the mean value
    }

    if(option == 2)       //<----- validaing the condition
    {
	for (int i = 0; i < n; i++)
	{
	    sum = sum + *((short *)ptr+i);   ///<----- adding the array elements, type casted as short type
	}
	mean =  sum / n;    
	return mean;       
    }

    if(option == 3)        //<---- validating the condition
    {
	for (int i = 0; i < n; i++)
	{
	    sum = sum + *((float *)ptr+i);    //<----- adding the array elements, type casted as float type
	}
	mean =  sum / n;
	return mean;
    }

    if(option == 4)    //<----- validating the condition
    {
	for (int i = 0; i < n; i++)
	{
	    sum = sum + *((double *)ptr+i);   //<----- adding the array elements, typecasted as double type
	}
	mean =  sum / n;
	return mean;
    }
}
