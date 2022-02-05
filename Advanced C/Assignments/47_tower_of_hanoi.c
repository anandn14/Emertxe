/*Documentation
Name: Anand N
Date: 08-12-2021
Description: To write a program implement the solution for tower of hanoi  
Sample i/p: 47_tower_of_hanoi.c
Sample o/p:
Enter number of disk N: 3
make the legal move disk 1 from rod A to C
make the legal move disk 2 from rod A to B
make the legal move disk 1 from rod C to B
make the legal move disk 3 from rod A to C
make the legal move disk 1 from rod B to A
make the legal move disk 2 from rod B to C
make the legal move disk 1 from rod A to C

Do you want to continue?(Y/y): y
Enter number of disk N: -4
Enter only positive numbers
Do you want to continue?(Y/y): n    */

#include <stdio.h>

void tower_of_hanoi(int, char, char, char);    //<----function prototype for tower of hanoi

int main()
{
    char ch;

    do        
    {
	int disk;   //<----declared the int variable

	printf("Enter number of disk N: ");
	scanf("%d", &disk);     //<---reading disks from user

	if(disk > 0)    //<----validating the condition for entered number is to be positive number 
	{ 
	    tower_of_hanoi(disk, 'A', 'C', 'B');   //<----function calling for tower of hanoi
	}
	else
	{
	    printf("Enter only positive numbers\n");
	}

	printf ("\nDo you want to continue?(Y/y): ");       
	scanf ("\n%c",&ch);                          //<----- reading the user choice for continue the process
    }while ( ch == 'Y' || ch == 'y' );          //<----- validating condition of user choice

    return 0;
}

void tower_of_hanoi(int N, char from, char to, char temp)
{
    if (N == 1)  //<---validating the condition for disk is equal to 1,(base condition)
    {
	printf("make the legal move disk %d from rod %c to %c\n", N, from, to);
	return;
    }
    tower_of_hanoi(N - 1, from, temp, to);   //<----recursive function call for moving disk next disk from-rod to temp-rod(to-rod)
    printf("make the legal move disk %d from rod %c to %c\n", N, from, to);
    tower_of_hanoi(N - 1, temp, to, from); //<---again recursive function call for moving remainig disk from temp-rod(from-rod) to to-rod
}
