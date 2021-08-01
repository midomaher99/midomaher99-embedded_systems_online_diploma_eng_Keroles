/*
 * reverse_sentence.c
 *
 *  Created on: Aug 1, 2021
 *      Author: Mohamed Mostafa
 */

#include <stdio.h>
#include <string.h>
void reverse_sentence(char sentence[]);
int main()
{
	char sentence[100];
	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	gets(sentence);
	reverse_sentence(sentence);
	printf("%s",sentence);
	return 0;
}
void reverse_sentence(char sentence[])
{
	char temp;
	int i, length = strlen(sentence)-1;
	for(i =0; i<= length/2 ; i++)
	{
		temp = sentence[i];
		sentence[i] = sentence[length-i];
		sentence[length-i] = temp;
	}
}
