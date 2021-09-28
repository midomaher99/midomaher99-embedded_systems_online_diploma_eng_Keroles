#include "stdio.h"
#include "student_management.h"

#define print(...) printf(__VA_ARGS__);fflush(stdin);fflush(stdout);

int main()
{
	while (1)
	{
		char temp_text[1];
		print("\n=====================================================================");
		print("\n\t choose one of the following options\n");
		print("\n1.add manually");
		print("\n2.view all");
		print("\n3.find roll");
		print("\n4.find first name");
		print("\n5.show students registered in course");
		print("\n6.view number of all students");
		print("\n7.update student");
		print("\n8.delete_student");


		print("\nEnter an option:");

		gets(temp_text);
		print("\n");

		switch(atoi(temp_text))
		{
		case 1:
			add_manually();
			break;
		case 2:
			view_all();
			break;
		case 3:
			find_roll();
			break;
		case 4:
			find_first_name();
			break;
		case 5:
			find_course();
			break;
		case 6:
			view_number_of_students();
			break;
		case 7:
			update_student();
			break;
		case 8:
			delete_student();
			break;

		default:
			print("wrong choice");
			break;
		}
	}
	return 0;
}
