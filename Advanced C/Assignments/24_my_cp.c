/*Documentation
Name: Anand N
Date: 22-01-2021
Description: Implement a my_cp() function 
Sample i/p: 24_my_cp.c
Sample o/p:
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out 
Please Enter source file and destination file
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out file1.txt 
Destination file missing
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out file1.txt file2.txt 
Data copied Succussfully
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out file.txt file2.txt 
Source file is not exist    */

#include<stdio.h>

void my_cp(FILE *, FILE *);       //<----- function prototype for my copy function
int main(int argc, char *argv[])  //<---- comamand line arguments paasing
{
    FILE *f1, *f2;     //<----- declared the file pointers

    switch (argc)     //<----- validating the argc
    {
	case 1:      
	    printf("Please Enter source file and destination file\n");
	    break;

	case 2:
	    printf("Destination file is missing\n");
	    break;

	case 3:

	    f1 = fopen(argv[1], "r");     //<----- opening te file with read mode

	    if (NULL == f1)       //<---- validating the condition for source file is exist or not
	    {
		printf("Source file is not exist\n");

		return 1;
	    }

	    f2 = fopen(argv[2], "w");   //<----- opening the file with write mode, if file is not exsit it will creat the file

	    my_cp(f2,f1);      //<----- function calling for my_cp

	    fclose(f1);      //<----- closing the file1
	    fclose(f2);      //<---- closing the file2

	    printf("Data copied Succussfully\n");
	    break;
	default:
	    printf("Too many arguments\n");
    }
    return 0;
}

void my_cp(FILE *f1, FILE *f2)   //<---- function definition for my copy function
{
    int c;                     
    while((c = fgetc(f1)) != EOF)   //<----- source file iterating over the while loop it encounters till the EOF
	fputc(c, f2);      //<----- copying the source file data to destination
}
