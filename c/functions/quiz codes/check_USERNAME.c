/*
 * check_USERNAME.c
 *
 *  Created on: Jul 27, 2021
 *      Author: Mohamed Mostafa
 */

#include"stdio.h"
#include"string.h"
int check_username(char username[]);
int main()
{
	char username[100];
	printf("Enter your username: ");
	fflush(stdin); fflush(stdout);
	scanf("%s", username);

	if(check_username(username) == 1)
		printf("SAME");
	else
		printf("NOT SAME");
	return 0;
}
int check_username(char username[])
{
	int i;
	char USERNAME[] ={"USERNAME"};
	for (i = 0; i < strlen(username); i++)
	{
		if(!(username[i] == USERNAME[i]))
		{
			return 0;
		}
	}
	return 1;
}
