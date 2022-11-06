#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable : 4996)

struct Lotto
{
	int lottoNumber;
	char lottoDate[11];
	struct Lotto* next;
	struct Lotto* prev;
};
struct Lotto* Head = NULL;
struct Lotto* Tail = NULL;


//A function to create a linked list
void AddToLinkedList(int lottoNumber, char lottoDate[11])
{
	struct Lotto* currentLottery = (struct Lotto*)malloc(sizeof(struct Lotto));
	if (currentLottery == NULL)
	{
		printf("Error Allocating Memory\n");
		exit(1);
	}
	else
	{
		currentLottery->lottoNumber = lottoNumber;
		strcpy(currentLottery->lottoDate, lottoDate);

		if (Head == NULL)
		{
			Head = currentLottery;
			Tail = currentLottery;
			currentLottery->next = NULL;
			currentLottery->prev = NULL;
		}
		else
		{
			Tail->next = currentLottery;
			currentLottery->prev = Tail;
			currentLottery->next = NULL;
			Tail = currentLottery;
		}
	}
}

//A function to read the file
void LoadFile()
{
	FILE* f = fopen("C:\\Users\\97252\\source\\repos\\Test-C\\Test-C\\Lotto.txt", "r");
	if (f == NULL)
	{
		printf("Error opening the file");
		return;
	}

	char str[1000];
	int lottoNumber;
	char lottoDate[11];
	char* token;

	fgets(str, 1000, f);

	while (fgets(str, 1000, f) != NULL) //Reads the file line after line and parsing it
	{
		token = strtok(str, ",");
		lottoNumber = atoi(token);
		token = strtok(NULL, ",");
		strcpy(lottoDate, token);
	
		AddToLinkedList(lottoNumber, lottoDate); //Send to AddToLinkedList function to create the linked list
	}

	fclose(f);
}


void FindTheDate(int num)
{
	struct Lotto* current = Head;

	while (current != NULL)
	{
		if (current->lottoNumber == num)
		{
			printf("The lottery number: %d took place on the date: %s\n", current->lottoNumber, current->lottoDate);
			return;
		}

		current = current->next;
	}

	printf("There is no such lottery number\n");
	return;
}


void PrintList()
{
	struct Lotto* current = Head;

	while (current != NULL)
	{
		printf("Lottery number: %d took place on the date: %s\n", current->lottoNumber, current->lottoDate);

		current = current->next;
	}
}

void FreeList()
{
	struct Lotto* current = Head;
	struct Lotto* release;

	while (current != NULL)
	{
		release = current;
		current = current->next;
		free(release);
	}
}


int main()
{
	LoadFile();
	PrintList();

	int num;

	char userResponse = NULL;
	while (userResponse != 'Q')
	{
		printf("\nPlease choose one of the following options:\nN-Find the Date of the lottery number\nQ-Quit the program\n");
		userResponse = getch();

		switch (userResponse)
		{
		case 'N':
			printf("Pleas enter the lottery number you wish to find: ");
			scanf("%d", &num);
			FindTheDate(num);
			break;
		case 'Q': //Exit the program
			FreeList();
			printf("Thank you for using my program.\n");
			break;

		default:
			printf("Wrong selection, please try again\n");
			break;
		}
	}

	return 0;
}
