#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int ADD(int num)
{
	printf("%d\n", num);
	return num >= 100 ? NULL : ADD(num + 1);
}


int main_3()
{
	ADD(1);

	return 0;
}