/*
 * 	Saad Arshad 00857432
 * 	CS2662 lab 208
 * 	lab 11
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
		int numbers;
		struct node *next;
}node;

void insertNode(node* head, int num);
void printList(node* head);
void deleteList(node* head);

int main(int argc, char *argv[] )
{
	//	Check if proper number of arguements was entered
	if ( argc != 4)
	{
		printf("Incorrect number of arguements entered.\n");
		exit(1);
	}
	
	//make a random number seed
	int seed;
	seed = atoi(argv[1]);
	srandom(seed);
	
	//set Number of random numbers to generate
	int numberofRan;
	numberofRan = atoi(argv[2]);
	
	//set max value of random number
	int maxValues;
	maxValues = atoi(argv[3]);
	
	//Create a node head with malloc and set it to next.
	node* head = malloc(sizeof(node));
	if(head == NULL)
	{
		printf("Error allocating memory for head node.\n");
		exit(1);
	}
	head -> numbers = -1;
	head -> next = NULL;

	long randNum;
	int i;
	int insert;
	
	printf("Generating random numbers:\n");
	
	for(i = 0; i < (numberofRan -1); i++)
	{
		randNum = random();
		insert = randNum % maxValues;
		printf("%d\n", insert);
		insertNode(head, insert);
	}
	
	printList(head);
	deleteList(head);
	return 0;
}

void insertNode(node* head, int num)
{
	node *holder = head;
	while(holder -> numbers > num)
	{
		holder = holder -> next;
	}
	node *newNode = malloc(sizeof(node));
	if(newNode == NULL)
	{
		printf("Error allocating memory.\n");
		exit(1);
	}
	newNode -> numbers = num;
	newNode -> next = NULL;
	
	holder -> next = newNode;
}
//prints the list of numbers
void printList(node* head)
{
	node *holder = head;
	printf("Numbers:\n");
	if(holder != NULL)
	{
		holder = holder -> next;
		while(holder != NULL)
		{
			printf("%d\n",holder -> numbers);
			holder = holder -> next;
		}
	}
}
//goes throw and frees the next and the head
void deleteList(node* head)
{
	node *holder, *holder1;
	
	if(head != NULL)
	{
		holder = head -> next;
		head -> next = NULL;
		
		while(holder != NULL)
		{
			holder1 = holder -> next;
			free(holder);
			holder = holder1;
		}
	}
	free(head);
}





