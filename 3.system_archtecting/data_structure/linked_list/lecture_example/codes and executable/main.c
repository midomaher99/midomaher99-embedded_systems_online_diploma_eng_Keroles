#include "stdio.h"
#include "string.h"
#include"linked.h"

#define print(...) printf(__VA_ARGS__);fflush(stdin);fflush(stdout);

void main()
{
	while (1)
	{
		char temp_text[40];
		print("\n=====================================================================");
		print("\n\t choose one of the following options\n");
		print("\n1.add student");
		print("\n2.delete student");
		print("\n3.view students");
		print("\n4.delete all");
		print("\nEnter an option:");
		
		gets(temp_text);
		print("\n");

		switch(atoi(temp_text))
		{
		case 1:
			add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			delete_All();
			break;
		default:
			print("wrong choice");
			break;
		}
	}
}
