#include "stdio.h"
#include "student_management.h"

#define print(...) printf(__VA_ARGS__);fflush(stdin);fflush(stdout);
#define scan(...) scanf(__VA_ARGS__);fflush(stdin);fflush(stdout);
int main()
{
	while (1)
	{
		char temp_text;
		print("\n=====================================================================");
		print("\n\t Choose one of the following options.\n");
		print("\n1.Add student.");
		print("\n2.View all.");
		print("\n3.Find roll.");
		print("\n4.Find first name.");
		print("\n5.Show students registered in course.");
		print("\n6.View number of all students.");
		print("\n7.Update student.");
		print("\n8.Delete_student.");
		print("\n9.Exit.")


		print("\nEnter an option:");

		scanf("%c",&temp_text);
		print("\n");

		switch(temp_text)
		{
		case '1':
			add_student();
			break;
		case '2':
			view_all();
			break;
		case '3':
			find_roll();
			break;
		case '4':
			find_first_name();
			break;
		case '5':
			find_course();
			break;
		case '6':
			view_number_of_students();
			break;
		case '7':
			update_student();
			break;
		case '8':
			delete_student();
			break;
		case '9':
			return 1;
			break;
		default:
			print("wrong choice");
			break;
		}
		print("\n\nDo you want something else?\n(y:for options, press any key:for exit)\n");
		scan("%c",&temp_text);

		if(!(temp_text == 'y'|| temp_text=='Y'))
			break;
	}
	return 0;
}
