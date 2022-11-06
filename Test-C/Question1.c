#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main_1()
{
	char str[100];
	printf("Please enter a string of up to 100 characters: ");
	gets(str);

	if (strlen(str) != 0)
	{
		if (strlen(str) == 1)
		{
			printf("The string contains only one character\n");
			return;
		}

		//Prints the left side of the string
		for (int i = 0; i < strlen(str) / 2; i++)
		{
			printf("%c", str[i]);
		}

		printf("\n");

		//Prints the right side of the string
		for (int i = strlen(str) / 2; i < strlen(str); i++)
		{
			printf("%c", str[i]);
		}
	}
	else
	{
		printf("The user did not enter a string\n");
	}

	return 0;
}