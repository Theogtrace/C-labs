/*  Saad Arshad
 *  G00857432
 *  CS 262, Lab Section 208
 *  lab 7
 *  Converts Ascii file to Binary files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCHAR 40
#define SLINE 10

int main(int argc, char *argv[])
{
	char charA[SLINE][SCHAR];
	char Buffer[300];
	char Buffer1[300];
	char Array1[SCHAR];
	int intBuffer[SLINE];
	double doubleBuffer[SLINE];
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

	// Read and write floating points.Reads each line and stores them in array called buffer, then sets doubleBuffer array at each instence to what was in the line using atof which changes the str to a floating point. then stores the whole doubleBuffer array in the outfile suing fwrite.   
	for(int i = 0; i < SLINE; i++)
	{	
		fgets(Array1, SCHAR, infile);
		doubleBuffer[i] = atof(Array1);
	}
	// sizeof(doubleBuffer[0]) to get the size of the element at the first index of the array. 
	fwrite(doubleBuffer, sizeof(doubleBuffer[0]), SLINE, outfile);
	
// Read and Write 10 lines of text using the charBuffer array. Store each line in buffer then just copy the buffer line into charBuffer array at each instance.  

	for(int i = 0; i < SLINE; i++)
	{
		fgets(Array1, SCHAR,infile);
		strcpy(charA[i], Array1);
	}
	// same as first one
	fwrite(charA, sizeof(charA[0]), SLINE, outfile);

//	Read and write signed integers. same thing as floating point but uses atoi instead. 
	for(int i = 0; i < SLINE; i++)
	{
		fgets(Array1, SCHAR, infile);
		intBuffer[i] = atoi(Array1);
	}
	// same as first one	
	fwrite(intBuffer, sizeof(intBuffer[0]), SLINE, outfile);

	printf("The file has been converted and saved to %s\n", Buffer1);
//	Close each file
	fclose(infile);
	fclose(outfile);
	return 0;
}









