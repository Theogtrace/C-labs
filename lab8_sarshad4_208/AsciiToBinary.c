/*  Saad Arshad
 *  G00857432
 *  CS 262, Lab Section 208
 *  lab 8
 *  Converts Ascii file to Binary files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCHAR 50
#define BSIZE 300


typedef struct _FileData
{
	int a;
	double b;
	char dataStr[50];
} FileData;

int main(int argc, char *argv[])
{

	char Buffer[BSIZE];
	char Buffer1[BSIZE];

	FileData data[BSIZE];
	int i = 0;
	// Check if the number of input on command line are 3
	if(argc != 3)
	{
		printf("Incorrect Number of Arguments!\n");
		exit(1);
	}
	
	printf("Program name %s\n", argv[0]);
	
	// Check each file that is being inputed if it is openning
	
	strcpy(Buffer, argv[1]);	
	FILE *infile = fopen(Buffer, "r");
	if(infile == NULL)
	{
		printf("Error opening input file.\n");
		exit(1);
	}
	
	strcpy(Buffer1, argv[2]);
	FILE *outfile = fopen(Buffer1, "w");
	if(outfile == NULL)
	{
		printf("Error opening output file\n");
		exit(1);
	}

	while(!feof(infile))
	{
		fgets(Buffer, BSIZE, infile);
		if(!feof(infile))
		{
			
 			data[i].a = atoi(Buffer);
	
			fgets(Buffer, BSIZE, infile);
			
			data[i].b = atof(Buffer);
			
			fgets(Buffer, BSIZE, infile);
			
			strcpy(data[i].dataStr, Buffer);
			
			i++;						
		}
	}		 	
	

	
	fwrite(data, sizeof(FileData), i, outfile);

	printf("The file has been converted and saved to %s\n", Buffer1);
//	Close each file
	fclose(infile);
	fclose(outfile);
	return 0;
}









