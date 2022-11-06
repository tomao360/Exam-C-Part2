#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main_2()
{
	char str[100];
	printf("Please enter a string of up to 100 characters: ");
	gets(str);

	int len = strlen(str);

	if (len != 0)
	{
		if (len == 1)
		{
			printf("The string contains only one character\n");
			return;
		}

		//Divides the left string in half each time and prints it
		while (len != 1)
		{
			for (int i = 0; i < len / 2; i++)
			{
				printf("%c", str[i]);
			}

			printf("\n");

			len = len / 2;
		}
	}
	else
	{
		printf("The user did not enter a string\n");
	}
	
	return 0;
}