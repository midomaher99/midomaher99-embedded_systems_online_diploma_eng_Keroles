#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define print(...) printf(__VA_ARGS__);fflush(stdin);fflush(stdout);

/*student data*/
struct Sdata
{
	int ID;
	char name[40];
	float height;
};

/*node*/
struct Sstudent
{
	struct Sdata student;
	struct Sstudent* Pnext_student;
};
/*_______________________________________________________________________________________________________*/
struct Sstudent* gpfirst_student = NULL;
/*_______________________________________________________________________________________________________*/
void add_student()
{
	struct Sstudent * pnew_student;
	struct Sstudent * plast_student;

	char temp_text[40];

	/*check empty*/
	if (gpfirst_student == NULL)
	{
		pnew_student =(struct Sstudent*) malloc(sizeof(struct Sstudent));
		gpfirst_student = pnew_student;
	}
	else
	{
		plast_student = gpfirst_student;

		while (plast_student->Pnext_student)
			plast_student = plast_student->Pnext_student;

		pnew_student =(struct Sstudent*) malloc(sizeof(struct Sstudent));
		plast_student->Pnext_student = pnew_student;
	}

	/*set last to Null*/
	pnew_student->Pnext_student = NULL;
	
	/*fill record*/
	print("Enter ID: ");
	gets(temp_text);
	pnew_student->student.ID = atoi(temp_text);

	print("Enter full name: ");
	gets(pnew_student->student.name);

	print("Enter height: ");
	gets(temp_text);
	pnew_student->student.height = atof(temp_text);

}
/*_______________________________________________________________________________________________________*/
int delete_student()
{
	char temp_text[40];
	unsigned int selected_id;

	/*get the selected ID*/
	print("Enter ID: ");
	gets(temp_text);
	selected_id = atoi(temp_text);

	/*check list is empty*/
	if (gpfirst_student)
	{
		struct Sstudent * pselected_student = gpfirst_student;
		struct Sstudent * pprevios_student = NULL;
		while (pselected_student)
		{
			if (pselected_student->student.ID == selected_id)
			{
				if(pprevios_student)
				{
					pprevios_student->Pnext_student = pselected_student->Pnext_student;
				}
				else /*delete first element*/
				{
					gpfirst_student =  pselected_student->Pnext_student;
				}

				free(pselected_student);
				print("students with ID:%d is deleted.", selected_id)
				return 1;
			}
			pprevios_student = pselected_student;
			pselected_student = pselected_student->Pnext_student;
		}
	}

	/*if not return then list is empty or id not found*/
	print("can not find student ID.");
	return 0;
}
/*_______________________________________________________________________________________________________*/
void view_students()
{
	struct Sstudent * pcurrent_student = gpfirst_student;
	int count =0 ;
	if (gpfirst_student == NULL)
	{
		print ("empty list");
	}
	else
	{
		while (pcurrent_student)
		{
			print("===============================\n")
			print("record number %d\n", count +1);
			print("ID: %d\n", pcurrent_student->student.ID);
			print("name: %s\n", pcurrent_student->student.name);
			print("Height: %.2f\n", pcurrent_student->student.height);

			pcurrent_student = pcurrent_student->Pnext_student;
			count ++;
		}
	}
}
/*_______________________________________________________________________________________________________*/
void delete_All()
{
	struct Sstudent * pcurrent_student = gpfirst_student;
	if (gpfirst_student == NULL){
		print ("empty list");}
	else
	{
		while (pcurrent_student)
		{
			struct Sstudent * ptemp = pcurrent_student;
			pcurrent_student = pcurrent_student->Pnext_student;
			free (ptemp);
		}
		gpfirst_student = NULL;
	}
	print("all students are deleted.");
}