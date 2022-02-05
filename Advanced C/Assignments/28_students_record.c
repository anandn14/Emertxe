/*Documentation
Name: Anand N
Date: 25-01-2022
Description: WAP to Implement the student record using array of strutures.
Sample i/p: 28_students_record.c
Sample o/p:
Enter number of students: 2
Enter number of subjects: 2
Enter name of the Subject 1: Maths
Enter name of the Subject 2: Science
-------------------------Enter students details--------------------
Enter the student 1 Roll Number: 01
Enter the student 1 name: Anand
Enter the Maths mark: 87
Enter the Science mark: 88
-------------------------Enter students details--------------------
Enter the student 2 Roll Number: 02
Enter the student 2 name: Rakesh
Enter the Maths mark: 90
Enter the Science mark: 92
-----------------------DISPLAY MENU-----------------------------
1. All Student Details
2. Particular Student Details
Enter your option: 1
Menu for All Student Details
Roll no		Name				Maths				Science				Average		Grade
1		Anand				87				88				87.5		B
2		Rakesh				90				92				91		A
Do you want to continue to display(y/Y): n
Do you want to continue(y/Y): n             */

#include <stdio.h>
#include <stdlib.h>

int my_strcmp(char *, char *);   //<----- function prototype for string compare
char grade(float);             //<------ function prototype for grade             

/* structure declaration */
struct student
{
    char name[30];
    int roll_num;
    int *mark;
};

int main()
{
    char ch1, ch2;                       //<----- declared the char variables
    do                    //<----- used do-while loop for continue the process
    {
	int stud = 0, subj = 0;
	char (*str)[30];
	int option, choice;
	float sum = 0, avg = 0;

	printf("Enter number of students: ");
	scanf("%d", &stud);                //<----- reading the no. of students from user    
	printf("Enter number of subjects: ");
	scanf("%d", &subj);               //<----- reading the no. of subjects from user

	str = malloc (sizeof(*str) *subj);  //<---- Dynamically memory allocated for subjects

	struct student S[stud];     //<------ declared the structure variable

	for (int i = 0; i < subj; i++)   //<---- iterating the no. of subjects over tyhe for loop
	{
	    printf("Enter name of the Subject %d: ", i + 1 );
	    scanf("%s", str[i]);                    //<--- reading subjects names from user
	}

	for (int i = 0; i < stud; i++)   //<---- iterating the no. of students over the for loo[
	{
	    printf("-------------------------Enter students details--------------------\n");
	    printf("Enter the student %d Roll Number: ", i + 1);
	    fflush(stdin);
	    scanf("%d", &S[i].roll_num);                    //<----- reading students roll number from user
	    printf("Enter the student %d name: ", i + 1);
	    fflush(stdin);
	    scanf("%s",S[i].name);                         //<----- reading names from user

	    S[i].mark = (int *) malloc(sizeof(int) * subj);  //<---- Dynamically memory allocated for storing marks

	    for (int j = 0; j < subj; j++)   //<---- iterating the no. of subjects over the for loop
	    {
		printf("Enter the %s mark: ", str[j]);
		scanf("%d", &S[i].mark[j]);                 //<------ reading marks from user
	    }
	}
	do
	{
	    printf("-----------------------DISPLAY MENU-----------------------------\n");
	    printf("1. All Student Details\n2. Particular Student Details\nEnter your option: ");
	    scanf("%d", &option);

	    switch (option)       //<----- validating the choice for partiular operation
	    {
		case 1 :      //<---- for all students
		    printf("Menu for All Student Details\n");
		    printf("Roll no\t\tName\t\t");

		    for(int j = 0; j < subj; j++)    //<----- iterating the no. of subjects over the for loop
		    {
			printf("\t\t%s\t\t", str[j]);     //<------ printing the subjects 
		    }

		    printf("\t\tAverage\t\tGrade\n");

		    for (int i = 0; i < stud; i++)   //<----- iterating the no. of students over the for loop
		    {
			sum = 0;
			for (int j = 0; j < subj; j++)  //<----- iterating the no. of subjects over the for loop
			{
			    sum = sum + S[i].mark[j];    //<----- expression for adding marks for each student
			}
			printf("%d\t\t%s\t\t", S[i].roll_num, S[i].name);  //<---- display students roll num and name

			for (int j = 0; j < subj; j++)   //<----- iterating the no. of subjects over the for loop
			{
			    printf("\t\t%d\t\t", S[i].mark[j]);    //<----- display marks of each subject
			}

			avg = sum / subj;              //<----- expression for finding avarage marks for each student

			printf("\t\t%g\t\t%c\n", avg, grade(avg));   //<----- display avg and grade
		    }

		    break;
		case 2 :      //<---- for particular students
		    {	
			printf("-----------------------Menu for particular student--------------------\n");
			printf("1. Name\n2. Roll no\nEnter your choice: ");
			scanf("%d",&choice);      //<----- reading the choice from user

			if (choice == 1)    //<---- validating the condition choice is to be 1
			{
			    char stud_name[50];

			    /* Prompt to read name of the student to display the detail of that particular student */
			    printf("Enter name of the student: ");
			    scanf("%s",stud_name);   //<--- reading the student name from user

			    sum = 0;
			    avg = 0;
			    int count = 0;

			    for (int i = 0; i < stud; i++)   //<---- iterating the no. of students over the for loop
			    {

				if ( my_strcmp (stud_name, S[i].name) == 0)  //<---- function calling for compare 
				{
				    count++;                          //<---- incrementing the count
				    printf("Roll No\t\tName\t\t");

				    for(int j = 0; j < subj; j++)   //<----- iterating the no. of subjects over the for loop
				    {
					printf("%s\t   ", str[j]);
					sum = sum + S[i].mark[j];   //<----- expression for adding marks for the student
				    }

				    avg = sum / subj;             //<---- exppression foor finding the avarage marks of the student

				    printf("Average\t\tGrade\n");
				    printf("%d\t\t%s\t\t",S[i].roll_num, S[i].name);

				    for(int j = 0; j < subj; j++)    //<----- iterating the subjects over the for loop
				    {
					printf("%d\t\t",S[i].mark[j] );
				    }

				    printf("%g\t\t%c\n",avg,grade(avg));

				}
			    }
			    if (count == 0)     //<---- validating the codition for count is to be 0
			    { 
				printf("%s student detail is not available\n", stud_name);
			    }
			}
			else if (choice == 2)    //<----- validating the choice is to be 2
			{
			    int number;
			    sum = 0;
			    avg = 0;                                  
			    printf("Enter the Student Roll Number: ");
			    scanf("%d",&number);          //<---- reading the students roll number from user

			    for (int i = 0; i < stud; i++)
			    {
				if (number == S[i].roll_num)      //<---- validating the condition for comparing roll number
				{
				    printf("Roll No\t\tName\t\t");

				    for(int j = 0; j < subj; j++)
				    {
					printf("%s\t   ", str[j]);
					sum = sum + S[i].mark[j];  //<----- expression for adding marks for student
				    }
				    avg = (sum / subj);     //<----- expression for finding the avarage marks of the student

				    printf("Average\t\tGrade\n");

				    printf("%d\t\t%s\t\t",S[i].roll_num, S[i].name);

				    for(int j = 0; j < subj; j++)
				    {
					printf("%d\t\t",S[i].mark[j] );
				    }

				    printf("%g\t\t%c\n",avg,grade(avg));
				}

			    }
			}
			else if (choice != 1 && choice != 2)     //<----- vaalidating the condition for choice is not 1 and 2
			    printf("Enter valid choice\n");
		    }
		    break;

		default :
		    printf("Enter valid option \n");
	    }

	    printf("Do you want to continue to display(y/Y): "); //<---- asks permisssion from user to repeat the operation
	    scanf("\n%c",&ch2);                         ///<---- reading the choice from user

	}while (ch2 == 'Y' || ch2 == 'y');  //<----- validating the condition of user choice to repeat the display function 

	free(str);          //<---- frees the memory
	str = NULL;
	printf("Do you want to continue(y/Y): ");  
	scanf("\n%c",&ch1);                   //<---- reading the choice from user

    }while (ch1 == 'Y' || ch1 == 'y');      //<---- validating the condition of user choice for repetetion of reading student details

    return 0;
}

char grade(float avg)     //<----- function definition for grade
{
    if ( avg >= 90 )    //<---- validating the condition avg is to greater than 90
    {
	return 'A';    //<---- returning grade A
    }
    else if (avg >= 80 && avg < 90)   //<---- validating the condition avg is greater than 80 & lesser than 90
    {      
	return 'B';    //<----- returning B
    }
    else if (avg >= 70 && avg < 80)    //<---- validating the condition avg is greater than 70 & lesser than 80
    {
	return 'C';   //<----- returning C
    }
    else if (avg >= 60 && avg < 70)    //<---- validating the condition avg is greater than 60 & lesser than 70
    {
	return 'D';   //<----- returning D
    }
    else if (avg >= 50 && avg < 60)    //<---- validating the condition avg is greater than 50 & lesser than 60
    {
	return 'E';   //<--- returning E
    }
    else
    {
	return 'F';    ///<--- retuning F
    }
}

int my_strcmp( char *str1, char *str2)   //<---- function definition for my string compare
{
    /* compare two strings with case insensitive */
    while ((*str1 && *str2) && (*str1 == *str2) || (*str1 - 32 == *str2) || (*str1 == *str2 - 32))
    {
	str1++;
	str2++;
    }
    return *str2 - *str1;    //<---- if both the strings are same means it will return 0 else ( >0 or <0) 
}
