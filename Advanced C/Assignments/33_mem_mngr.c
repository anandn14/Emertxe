/*Documentation
Name: Anand N
Date: 05-01-2022
Description: To take 8 consecutive bytes in memory. Provide a menu to manipulate or display the value of variable of type t (input) & indexed at i (i/p)
Sample i/p: 33_mem_mngr.c
Sample o/p:
Select function:
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Enter your choice: 1
Enter the type you have to insert:
1. int
2. char
3. short
4. float
5. double
Enter your choice: 1
Enter the integer: 10
Select function:
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Enter your choice: 1
Enter the type you have to insert:
1. int
2. char
3. short
4. float
5. double
Enter your choice: 3
Enter the integer (short): 2
Select function:
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Enter your choice: 1
Enter the type you have to insert:
1. int
2. char
3. short
4. float
5. double
Enter your choice: 2
Enter the character: A
Select function:
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Enter your choice: 1
Enter the type you have to insert:
1. int
2. char
3. short
4. float
5. double
Enter your choice: 2
Enter the character: b
Select function:
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Enter your choice: 3
[0] -> A	(char_type)
[1] -> b	(char_type)
[2] -> 2	(short_type)
[3] -> 10	(int_type)
Select function:
1. Add element
2. Remove element
3. Display element
4. Exit from the program
Enter your choice: 4    */

#include<stdio.h>
#include<stdlib.h>
    int main()
{
    int choice, option, i;		
    int pos[5];

    int c_flag = 0, s_flag = 0, i_flag = 0, f_flag = 0, d_flag = 0;

    void *ptr;
    ptr = malloc(8 * sizeof(char));	//<---- allocating 8 byte consecutaive memory

    while (1)
    {
	printf("Select function:\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\nEnter your choice: ");	
	scanf("%d", &choice);	
	switch (choice)
	{
	    case 1:   //<----- for add elements		
		{
		    printf("Enter the type you have to insert:\n1. int\n2. char\n3. short\n4. float\n5. double\n");
		    printf("Enter your choice: ");
		    scanf("%d", &option);		

		    switch (option)
		    {
			case 1:
			    if (i_flag == 0 && f_flag == 0 && d_flag == 0)   //<---- validatimg the condition flags values is to be 0
			    {
				i_flag++;                      //<--- incrementing the i_flag
				printf("Enter the integer: ");	
				scanf("%d",((int*)ptr) + 1);		//<----- reading the int value from user
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			case 2:
			    if(c_flag < 2 && d_flag == 0)  //<--- validating the condition for c_flag value < 2 & d_flag value is to be  0
			    {
				printf("Enter the character: ");   
				scanf(" %c", ((char*)ptr) + c_flag);    //<---- reading the character from user 
				c_flag++;                     
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			case 3:
			    if (s_flag == 0 && d_flag == 0)    //<---- validating the condition for s-flag value & d_flag value is to be 0
			    {
				s_flag++;             //<--- incrementing the s_flag
				printf("Enter the integer (short): ");
				scanf("%hd", ((short*)ptr) + 1);	//<--- reading the short number from user
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			case 4:
			    if (i_flag == 0 && f_flag == 0 && d_flag == 0) //<---- validating the condition for flags value is to be 0
			    {
				f_flag++;
				printf("Enter the float value: ");
				scanf("%f", ((float*)ptr) + 1);	         //<--- reading the float number from user  
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			case 5:
			    if (c_flag == 0 && i_flag == 0 && s_flag == 0 && f_flag == 0 && d_flag == 0)
			    {
				d_flag++;
				printf("Enter the double value: ");
				scanf("%lf", ((double*)ptr) );		//<---- reading the double value from user
			    }
			    else
				printf("Memory is occupied\n");
			    break;
			default :
			    printf("Invalid option\n");
		    }
		    break;			
		}
	    case 2:	    //<----- for remove element
		{
		    i = 0;	
		    /*printing  with the position of the 8 consecutive memory */
		    if (c_flag > 0)
		    {
			printf("[%d] -> %c\n", i, *((char*)ptr));	//<----- 1st char
			pos[i++] = 1;
			if (c_flag > 1)
			{
			    printf("[%d] -> %c\n", i, *(((char*)ptr)+ 1));	//<--- 2nd char
			    pos[i++] = 1;
			}
		    }
		    if (s_flag == 1)
		    {
			printf("[%d] -> %hd\n", i, *(((short*)ptr) + 1));	//<---- 3rd and 4th for short
			pos[i++] = 2;
		    }
		    if (i_flag == 1)
		    {
			printf("[%d] -> %d\n", i, *(((int*)ptr) + 1));      //<---- 5th to 8th for int
			pos[i++] = 3;
		    }
		    if (f_flag == 1)
		    {
			printf("[%d] -> %f\n", i, *(((float*)ptr) + 1));	//<---- 5th to 8th for float
			pos[i++] = 4;
		    }
		    if (d_flag == 1)
		    {
			printf("[%d] -> %lf\n", i, *((double*)ptr));      //<----- whole memory to double
			pos[i++] = 5;
		    }
		    printf("Enter the index value to be deleted: ");
		    scanf("%d", &i);	     //<---- reading the index value from user

		    switch (pos[i])
		    {
			case 1:             //<---- for removing char
			    if (c_flag > 0)	//<---- validating the condition for c flag value is greater than 0 or not
			    {
				if (i == 0)  //<--- validating the condition index value is to be 0
				{
				    *((char*)ptr) = *(((char*)ptr)+ 1);
				    c_flag--;    //<----- decrementing the c flag value
				}
				if (i == 1)  //<----- validating the condition index value is to be 1
				{
				    c_flag--;
				}
				printf("Index %d is successfully deleted\n", i);
			    }
			    else
				printf("Already deleted\n");
			    break;
			case 2:	               //<---- for removing short
			    if (s_flag == 1)    //<--- vlidating the condition for s falg value is to be 1
			    {
				s_flag--;
				printf("Index %d is successfully deleted\n",i);
			    }
			    else
				printf("Already deleted\n");
			    break;
			case 3:              //<----- for removing int
			    if (i_flag == 1) //<--- validating the condition for i flag value is to be 1
			    {
				i_flag--;
				printf("Index %d is successfully deleted\n", i);
			    }
			    else
				printf("Already deleted\n");
			    break;
			case 4:	                 //<----- for removing float
			    if (f_flag == 1)   //<---- validating the condition for f flag value is to be 1
			    {
				f_flag--;
				printf("Index %d is successfully deleted\n", i);
			    }
			    else
				printf("Already deleted\n");
			    break;
			case 5:	               //<----- for removing double
			    if (d_flag == 1)
			    {
				d_flag--;
				printf("Index %d is successfully deleted\n", i);
			    }
			    else
				printf("Already deleted\n");
			    break;
			default :
			    printf("Invalid optioni\n");
		    }
		    break;
		}
	    case 3:        //<---- for displaying the element
		{
		    i = 0;
		    if (c_flag > 0)   //<--- validating the condition of char flag for dispalaying the char type
		    {
			printf("[%d] -> %c\t(char_type)\n", i++, *((char*)ptr));

			if (c_flag > 1)
			    printf("[%d] -> %c\t(char_type)\n", i++, *(((char*)ptr)+ 1));	
		    }
		    if (s_flag == 1)    //<--- validating the condition of short flag for displaying the short type
			printf("[%d] -> %hd\t(short_type)\n",i++, *(((short*)ptr) + 1));

		    if (i_flag == 1)   //<---- validating the condition of int flag for displaying the int type
			printf("[%d] -> %d\t(int_type)\n", i++, *(((int*)ptr) + 1));

		    if (f_flag == 1)   //<---- validating the condition of float flag for displaying the int type
			printf("[%d] -> %f\t(loat_type)\n", i++, *(((float*)ptr) + 1));

		    if (d_flag == 1)  //<---- validating the condition of double flag for displaying the int type
			printf("[%d] -> %lf\t(double_type)\n", i++, *((double*)ptr));

		    if (c_flag == 0 && i_flag == 0 && s_flag == 0 && f_flag == 0 && d_flag == 0)
			printf("Nothing available all indexes are empty\n"); 
		    break;
		}
	    case 4:      //<---- for exit the program
		free(ptr);    //<---- frees the allocated memory
		ptr = NULL;   //<--- assigning the NULL to the ptr
		exit(1);
		break;
	    default :
		printf("Invalid option\n");
	}
    }
}
