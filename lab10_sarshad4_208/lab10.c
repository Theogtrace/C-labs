/*
 * 	Saad Arshad 00857432
 * 	CS 262 Section 208
 * 	lab 10
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BSIZE 100
#define NAME_SIZE 25

typedef struct _Item
{
	char name[NAME_SIZE];
	size_t quantity;
	double price;
}Item;

Item *createItems(int size)
{
	Item *item = NULL;
	item = (Item*)malloc(size*sizeof(Item));
	if(item == NULL)
	{
		printf("Error with malloc in createItems!\n");
		exit(1);	
	}
	for(int i = 0; i < size; i++)
	{
		item[i].name[0] = '\0';
		item[i].quantity = 0;
		item[i].price = 0.0;
	}
	return item;
}

int getPrintMenu(char[]);
void addItem(Item [],int , char[]);

int main()
{
	Item *data;

	int x = 0;
	int choice;
	char Buffer[BSIZE];
	int size = 0;
	int count = 0;
	int d = 0;
	

	printf("How many items would you like in your shopping card?\n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%d", &size);

	data = createItems(size);

	while(x != 3)
	{
		choice = getPrintMenu(Buffer);
		switch(choice)
		{
			case 1:
				d++;
				if(d > size)
				{	
					Item *blankA = data;
					data = createItems(size*2);
					memcpy(data, blankA, sizeof(Item)*size);
				}
				addItem(data, count, Buffer);
				count++;
				break;
			case 2:
				for(int i = 0; i < count; i++)
				{
					printf("Name: %s", data[i].name);
					printf("Quantity: %lu\n", data[i].quantity);
					printf("Price: %lf\n", data[i].price);		
				}
				break;
			case 3:
				printf("Quiting the program!\n");
				free(data);
				x = 3;
				break;
	
			default:
				printf("invalid input.\n");
				break;
		}
	}

}

int getPrintMenu(char Buffer[])
{
	int choice = 0;
	
	printf("\nAdd an Item to the Shopping Cart!\n");
	printf("Print the current list of Items.\n");
	printf("Quit the program\n");
	
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%d", &choice);
	return choice;
}

void addItem(Item *data, int count, char Buffer[])
{
	printf("What is the name of the item?\n");	
	fgets(data[count].name, NAME_SIZE, stdin);
	//strcpy(nameArray, Buffer);

	printf("What is the Quantitny of the item?\n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%lu", &data[count].quantity);	

	printf("What is the price of the item?\n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%lf", &data[count].price);

}
