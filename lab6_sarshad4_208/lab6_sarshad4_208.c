/* Saad Arshad G#00857432
 * CS 262 , 208
 * lab6
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BSIZE 1000
#define CSIZE 20


int main()
{
	char Buffer[BSIZE];
	char Line[BSIZE];
	char Filein[BSIZE];
	char Fileout[BSIZE];

	FILE *infile = NULL;
	FILE *outfile = NULL;
	char *token = NULL;	
	char s[CSIZE] = " ";
	int x = 0;
	int count;

	char A[BSIZE];
	char B[BSIZE];
// Initializing the Arrays that the words will be stored to		
	A[0] = '\0';
	B[0] = '\0';
	Line[0] = '\0';
// asking user to input the file that will be read
	printf("What file do you want to open?\n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%s", Filein);

	infile = fopen(Filein,"r");	
// always check if the file was opened
	if(infile == NULL)
	{
		printf("Error opening file \n");
		exit(1);
	}
	
	printf("What file do you want to write to?\n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%s", Fileout);

	outfile = fopen(Fileout, "w");

	if(outfile == NULL)
	{
		printf("Error opening file\n");	
		exit(1);
	}
	
// reads each of the line from the pharagram and puts in Line array
	while(fgets(Line, BSIZE, infile))
	{
		
		printf("%s\n", Line);
		printf("What word do you want to get rid off?\n");
		fgets(Buffer, BSIZE, stdin);
		sscanf(Buffer, "%d", &x);
		
// uses strtok to separate each word in the Line array of each sentance
		token = strtok(Line,s);
		count = 0;
		
		while(token != NULL)
		{	
// Count is just a counter variable that goes up each time and this if statement // uses strcat to add the token to a blank array A. also removes the \n 
			if(count != x || x <= 0)
			{
				strcat(A, token);
				if(token[strlen(token) -1] == '\n')
				{
					token[strlen(token)-1] = '\0';
				}
				else
				{
					strcat(A, " ");
				}	
			}
// if the count variable is the same as x which is the input of what ward the user wants to get rid off than it gets coppied to array B for the output file. 
			else if(count == x)
			{
				strcat(B, token);
				fprintf(outfile, "%s\n", B);
			}

			token = strtok(NULL,s);
			B[0] = '\0';
			count = count + 1;	
		}
		
	}

	printf("This is the new msg\n");
	printf("%s\n", A);

	fclose(infile);
	fclose(outfile);
	exit(0);
	
}



