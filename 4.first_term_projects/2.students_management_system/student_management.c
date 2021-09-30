#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define print(...) printf(__VA_ARGS__);fflush(stdin);fflush(stdout);
#define scan(...) scanf(__VA_ARGS__);fflush(stdin);fflush(stdout);

typedef struct Sstudent_data{
	char first_name[50];
	char last_name [50];
	int roll_num;
	float GPA;
	int course_id[5];
}student_data_t;

typedef struct node{
	student_data_t student;
	struct node * Pnext_student;
} student_t;

typedef struct{
	student_t * base;
	student_t * tail;
	student_t * head;
	int counter;
}fifo_t;

fifo_t buff = {NULL,NULL,NULL,0};

void add_node()
{
	if (buff.base)
	{
		buff.head->Pnext_student = (student_t*) malloc(sizeof(student_t));
		buff.head = buff.head->Pnext_student;
	}
	else /*queue is empty*/
	{
		buff.base = buff.tail = buff.head = (student_t*) malloc(sizeof(student_t));
	}
	buff.head->Pnext_student =NULL;
}

void fill_record(unsigned int roll)
{
	char temp_text[50];
	int i;

	buff.head->student.roll_num = roll;

	print("Enter student first name:");
	gets(buff.head->student.first_name);

	print("Enter student last name:");
	gets(buff.head->student.last_name);

	print("Enter student GPA:");
	gets(temp_text);
	buff.head->student.GPA = atof(temp_text);

	print("Enter the ID of five courses: \n");
	for (i = 0; i<5; i++)
	{
		print("course number %d ID:",i+1);

		gets(temp_text);
		buff.head->student.course_id[i] = atoi(temp_text);
	}
}

void add_student()
{
	student_t * current_student ;
	unsigned int selected_roll;
	short flag=0;
	do
	{
		current_student = buff.tail;
		flag =0;
		print("Enter student roll number:");
		scan("%d",&selected_roll);

		while (current_student)
		{
			if (current_student->student.roll_num == selected_roll)
			{
				print("this roll number is already taken.\n");
				flag =1;
			}
			current_student=current_student->Pnext_student;
		}
	}while (flag ==1);
	add_node();
	fill_record(selected_roll);
	buff.counter ++;
}

void view_student(student_t * current_student)
{
	int i;
	print("===========\n");
	print("roll number: %d\n",current_student->student.roll_num );
	print("first name: %s\n", current_student->student.first_name);
	print("last name: %s\n", current_student->student.last_name);
	print("GPA: %.2f\n", current_student->student.GPA);
	for (i = 0; i<5; i++)
		print("course number %d ID:%d\n",i+1,current_student->student.course_id[i]);
}

void find_roll()
{
	student_t * current_student = buff.tail;
	unsigned int selected_roll;
	print("Enter roll number to view:");
	scanf("%d",&selected_roll);
	while (current_student)
	{
		if (current_student->student.roll_num == selected_roll)
		{
			view_student(current_student);
			return;
		}
		current_student= current_student->Pnext_student;
	}
	print("can not find roll number");
}

void find_first_name()
{
	student_t * current_student = buff.tail;
	char selected_name[50];
	int counter=0;
	print("Enter student first name to view:");
	gets(selected_name);
	while (current_student)
	{
		if (!strcmp(current_student->student.first_name, selected_name))
		{
			view_student(current_student);
			counter++;
		}
		current_student= current_student->Pnext_student;
	}
	if(counter==0)
		print("can not find student name");
}

void find_course()
{
	student_t * current_student = buff.tail;
	int selected_id, counter =0,i;

	print("Enter course ID to show registered students:")
	scanf("%d",&selected_id);
	while (current_student)
	{
		for(i=0;i<5;i++)
		{
			if (current_student->student.course_id[i]== selected_id)
			{
				view_student(current_student);
				counter ++;
				break;
			}
		}
		current_student= current_student->Pnext_student;
	}
	if(counter==0)
		print("No students are registered in this course.\n");
}

void view_all()
{
	student_t * current_student = buff.tail;
	int count =0;

	switch((int)current_student)
	{
	case 0:
		printf("no students to show.\n");
		break;
	default:
		while (current_student)
		{
			print("===============================\n")
			print("record number %d\n", count +1);
			view_student(current_student);
			current_student = current_student->Pnext_student;
			count ++;
		}
		break;
	}
}

void view_number_of_students()
{
	print("number of all students is: %d.",buff.counter);
}

void delete_student()
{
	student_t * current_student = buff.tail;
	student_t * prev_student = NULL;
	unsigned int selected_roll;
	print("Enter roll number to delete:");
	scanf("%d",&selected_roll);

	while (current_student)
	{
		if (current_student->student.roll_num == selected_roll)
		{
			if(prev_student)
			{
				prev_student->Pnext_student = current_student->Pnext_student;
			}
			else
			{
				buff.base=buff.tail= current_student->Pnext_student;
				if (buff.counter == 1)
					buff.head = current_student->Pnext_student;

				buff.counter--;

			}
			free(current_student);
			print("student has roll number: %d is deleted.\n",selected_roll)
			return;
		}
		prev_student = current_student;
		current_student= current_student->Pnext_student;
	}
	print("can not find roll number");
}

void update_student()
{
	student_t * updated_student = buff.tail;
	char temp_text[40] = {0};
	int i;
	print("Enter roll number to update:");
	gets(temp_text);
	while (updated_student)
	{
		if (updated_student->student.roll_num == atoi(temp_text))
		{

			do
			{
				print("Enter a choice.\n");
				print("1.update roll number.\n");
				print("2.update first name.\n");
				print("3.update last name.\n");
				print("4.update GPA.\n");
				print("5.update course ID.\n");

				gets(temp_text);
				switch (atoi(temp_text))
				{	
					student_t * current_student ;
					unsigned int updated_roll;
					short flag=0;
					
					case 1:
						do
						{
							print("Enter new roll number:");
							scan("%d",&updated_roll);
							if (updated_roll == updated_student->student.roll_num)
								break;
						
							current_student = buff.tail;
							flag =0;
						
							while (current_student)
							{
								if (current_student->student.roll_num == updated_roll)
								{
									print("this roll number is already taken.\n");
									flag =1;
								}
								current_student=current_student->Pnext_student;
							}
						}while (flag ==1);

						updated_student->student.roll_num = updated_roll;
						break;
					case 2:
						print("Enter first name:");
						gets(updated_student->student.first_name);
						break;
					case 3:
						print("Enter last name:");
						gets(updated_student->student.last_name);
						break;
					case 4:
						print("Enter new GPA:");
						gets(temp_text);
						updated_student->student.GPA = atof(temp_text);
						break;
					case 5:
						print("registered courses:");
						for (i = 0; i < 5; i++)
						{
							print("course number %d: %d\n",i+1 ,updated_student->student.course_id[i]);
						}
						print("which course ID you need to update:");
						gets(temp_text);
						i = atoi(temp_text);
						print("Enter new course ID:");
						gets(temp_text);
						updated_student->student.course_id[i] = atoi(temp_text);
						break;
					default:
						print("wrong choice.\n");
						break;
				}

				print("do you want to update another data for this student:(y/n)" );
				gets(temp_text);
			}
			while(!strcmp(temp_text, "y"));
		return;
		}
		updated_student= updated_student->Pnext_student;
	}
	print("can not find roll number");
}