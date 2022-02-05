/*Documentation
Name: Anand N
Date: 23-01-2022
Description: WAP to concatenate two files
Sample i/p: 25_my_cat.c
Sample o/p:
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out 
hi
hi
^C
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out file1.c 
Hello
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out file2.c 
program exicuted
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out file1.c file2.c 
Hello
program exicuted
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ ./a.out file1.c file2.c file3.c
anandn@anandn-Inspiron-3541:~/ECEP/C/Assignments$ cat file3.c 
Hello
program exicuted      */


#include<stdio.h>
void my_cp(FILE *f1, FILE *f2);   //<---- function definition for my copy function
int main(int argc, char *argv[])
{

    FILE *f1, *f2, *f3;    //<---- declared the file pointers

    switch(argc)      //<----- validating the argument count
    {
	case 1:
	    my_cp(stdin,stdout);    //<---- for no file passed input stream copying the output stream
	    break;
	case 2:
	    f1 = fopen(argv[1], "r");   //<---- opeing the file1 with read mode
	    
	    if(f1 == NULL)        //<---- validating the condition for file exist or not
	    {
		printf("File not exist\n");
		return 1;
	    }
	    my_cp(f1, stdout);    //<---- function calling for copying the data from file to stdout stream
	    fclose(f1);          //<---- closing the file
	    break;
	case 3:
	    f1 = fopen(argv[1], "r");  //<----- opening the file1 with read mode
	    f2 = fopen(argv[2], "r");  //<----- opening the file2 with read mode

	    if(f1 == NULL || f2 == NULL)   //<----- validating the condition for file1 or file2 are exist or not
	    {
		printf("File not exist\n");
		return 1;
	    }

	    my_cp(f1, stdout);     //<---- function calling for the copying the data from file1 to stdout stream
	    my_cp(f2, stdout);     //<---- function calling for the copying the data from file2 to stdout stream

	    fclose(f1);          //<----- closing the file1
	    fclose(f2);          //<---- closing the file2
	    break;
	case 4:
	    f1 = fopen(argv[1], "r");   //<----- opening the file1 with read mode
	    f2 = fopen(argv[2], "r");   //<---- opening the file2 with read mode
	    f3 = fopen(argv[3], "w");   //<---- opning the file3 with write mode, if its not exist it will create file3

	    if(f1 == NULL || f2 == NULL)   //<---- validating the condition for file1 & file2 are exists are not
	    {
		printf("File not exist\n");
		return 1;
	    }

	    my_cp(f1, f3);    //<---- function calling for copying the datafrom file1 to file3
	    my_cp(f2, f3);    //<---- function calling for copying the datafrom file2 to file3


	    fclose(f1);   //<----- closing the file1
	    fclose(f2);   //<---- closing the file2
	    fclose(f3);   //<----- closing the file
	    break;
	default:
	    printf("Enter only 3 files\n");
    }
}

void my_cp(FILE *f1, FILE *f2)   //<---- function definition for my copy function
{
    int c;                     
    while((c = fgetc(f1)) != EOF)   //<----- source file iterating over the while loop it encounters till the EOF
	fputc(c, f2);      //<----- copying the source file data to destination
}
