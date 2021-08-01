/*
 *	simple program using structure concept
 *  Created on: Jul 28, 2021
 *      Author: moham
 */

#include "stdio.h"
struct S_student{
	char name[100];
	int roll;
	float marks;
};
int main()
{
	struct S_student student1;
/************************************************************************/
		/*taking inputs from user*/
	printf("Enter Student name: ");
	fflush(stdin); fflush(stdout);
	gets(student1.name);

	printf("Enter Student roll number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &student1.roll);

	printf("Enter Student roll: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &student1.marks);
/************************************************************************/
		/*displaying data*/
	printf("\nthe student name : %s", student1.name);
	printf("\nthe student roll number : %d", student1.roll);
	printf("\nthe student marks : %.2f", student1.marks);
	return 0;
}
