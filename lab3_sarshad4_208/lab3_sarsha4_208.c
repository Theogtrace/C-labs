/*
 *  * Saad Arshad 00857432
 *   * CS 262, Lab Section 208
 *    * Lab 3
 *     */

#include <stdio.h>
#include <stdlib.h>
#define BSIZE 100


char getPrintMenu(char , char[]);
void getplusFigure(char, int);
char getcharChoice(char, char[]);
int getnumChoice(int , char[]);
void getxFigure(char , int);
int main()
{
	int x = 0;
	while(x != 6)
	{
		char Buffer[BSIZE];
		char choice;
		choice = getPrintMenu(choice, Buffer);
		char characterChosen;
		int  numberChosen;

		switch (choice)
		{
			case 'C':
			case 'c':
				characterChosen = getcharChoice(characterChosen , Buffer);		
				break;

			case 'N':
			case 'n':
				numberChosen = getnumChoice(numberChosen, Buffer);
				break;

			case '1':
				getplusFigure(characterChosen, numberChosen);
				break;
			case '2':
				getxFigure(characterChosen, numberChosen);
				break;
			case 'Q':
			case 'q':
				printf("Closing Program.\n");
				x = 6;
				break;
			default:
				printf("Invalid input.\n");
				break;

		}//switch


	}//while



}

char getPrintMenu(char choice, char Buffer[]) 
{
	printf("Enter/Change Character C or c\n");
	printf("Enter/Change Number N or n\n");
	printf("Print Plus (+) Figure 1 \n");
	printf("Print X Figure 2 \n");
	printf("Quit Program Q or q\n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%c", &choice);
	return choice;	

}

char getcharChoice(char characterChosen, char Buffer[])
{
	printf("Enter your choice of character \n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%c", &characterChosen);
	return characterChosen;	
} 

int getnumChoice(int numberChosen, char Buffer[])
{
	int valid = 0;
	do
	{
		printf("Enter your number choice \n");
		fgets(Buffer, BSIZE, stdin);
		sscanf(Buffer,"%d", &numberChosen);
		if(numberChosen >= 3 && numberChosen <= 15 && numberChosen%2 == 1)
		{
			valid = 1;
		}
		else
		{
			printf("Invalid entry, please reenter input.\n");
			//valid = 0;
		}
	}while(valid == 0);
	return numberChosen;
}


void getplusFigure(char x, int size)
{
	int r;
	int c;
	//int size = y;
	//printf("SIZE: %d\n", size);
	for(r = 0; r < size; r++)
	{
		//printf("R: %d\n", r);
		for(c = 0; c < size; c++)
		{
			//printf("C: %d\n", c);
			if(r == size/2)
			{
				printf("%c",x);
			}
			else if(c == size/2)
			{
				printf("%c",x);
			}
			else 
			{
				printf(" ");
			}
		}printf("\n"); 
	}			
	


}


void getxFigure(char x, int size)
{
	int r;
	int c;

	for(r=0; r < size; r++)
	{
		for(c = 0; c < size; c++)
		{
			if(r==c || r+c == size -1)
			{
				printf("%C", x);
			}
			else
			{
				printf(" ");
			}
		}printf("\n");
	}


}












