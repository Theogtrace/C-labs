/* Saad Arshad
 * G#00857432
 * CS262 lab7 section 208
 * Converts Binary to Ascii value
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCHAR 40
#define SLINE 10


int main(int argc, char *argv[])
{
	int intA;
	double doubleBuffer;
	char charA[SCHAR];

	if(argc != 3)
	{
		printf("Incorrect number of agruements.\n");
		exit(1);
	}
	
	printf("The name of the program is %s\n", argv[0]);
//	Open each file and check for null pointers
	
	char Buffer[300];
	char Buffer1[300];

	strcpy(Buffer, argv[1]);
	FILE *infile = fopen(Buffer, "r");
	if(infile == NULL)
	{
		printf("Error opening input file\n");
		exit(1);
	}
	
	strcpy(Buffer1, argv[2]);
	FILE *outfile = fopen(Buffer1, "w");
	if(outfile == NULL)
	{
		printf("Error opening output file\n");
		exit(1);
	}
	
//	Read using fread, and write floats to the 4th decimal place. use fread to read each line and store it in the doublebuffer which not an array so we use & sign to store it in the variable value and then just write that variable that is hold the info into the outfile using fprintf at each line in the for loop. 
	for(int i = 0; i <SLINE; i++)
	{
		fread(&doubleBuffer, sizeof(double), 1, infile);
		fprintf(outfile, "%.4lf\n", doubleBuffer);
	}
	
//	Read and write strings. Use fread to store a string of char at each line into the charA array and just store that whole line of string into the output file using fprintf at each line instead of having to convert all of them and then store its easier to just store each line at a time. 
	for(int i = 0; i <SLINE; i++)
	{
		fread(charA, sizeof(char), SCHAR, infile);
		fprintf(outfile, "%s", charA);
	}

//	Read and write integers. The same as floating point but just use int instead. 
	for(int i = 0; i <SLINE; i++)
	{
		fread(&intA, sizeof(int), 1, infile);
		fprintf(outfile, "%d\n", intA);
	}
	
	printf("The file has been converted and save to %s\n", Buffer1);
//	Close each file
	fclose(infile);
	fclose(outfile);
	return 0;

}
