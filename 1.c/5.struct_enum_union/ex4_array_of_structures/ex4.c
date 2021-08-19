/*
 * students_data_struct_array.c
 *
 *  Created on: Aug 4, 2021
 *      Author: moham
 */

#include<stdio.h>
struct Sstudent_data
{
	int roll;
	char name[50];
	float marks;
};
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i;
	struct Sstudent_data student[10];
	printf("Enter information of students:\n\n");

	for(i =0; i<10;i++)
	{
		printf("Enter roll number: ");
		scanf("%d", &student[i].roll);
		printf("Enter student name: ");
		fflush(stdin);
		gets(student[i].name);
		printf("Enter marks: ");
		scanf("%f", &student[i].marks);
		printf("\n");
	}
	printf("\nStudents data\n");
	for(i =0; i<10;i++)
	{

		printf("Information for roll number: %d\n",student[i].roll);
		printf("Names: %s\n",student[i].name);
		printf("Marks: %.2f\n",student[i].marks);
	}

	return 0;
}
