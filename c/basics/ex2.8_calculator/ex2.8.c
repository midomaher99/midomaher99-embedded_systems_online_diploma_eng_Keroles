#include "stdio.h"

void  main()
{
char procces;
float operand1, operand2;

printf ("Enter procces + or - or * or / : ");
fflush(stdin);
fflush(stdout);
scanf("%c", &procces);

printf("Enter two operands:");
fflush(stdin);
fflush(stdout);
scanf("%f %f", &operand1, &operand2);

switch(procces)
{
	case '+':
		printf("%f %c %f = %f", operand1, procces, operand2, operand1 + operand2);
		break;
	case '-':
		printf("%f %c %f = %f", operand1, procces, operand2, operand1 - operand2);
		break;
	case '*':
		printf("%f %c %f = %f", operand1, procces, operand2, operand1 * operand2);
		break;
	case '/':
		printf("%f %c %f = %f", operand1, procces, operand2, operand1 / operand2);
		break;
	default:
	printf("not valid operator");
	break;
}

}