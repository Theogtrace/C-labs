/* Saad Arshad
 * G#00857432
 * CS262 lab7 section 208
 * Converts Binary to Ascii value
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCHAR 50
#define SLINE 10
#define BSIZE 300

typedef struct _FileData
{
	int a;	
	double b;
	char dataStr[50];

} FileData;

int main(int argc, char *argv[])
{

	FileData data;

	if(argc != 3)
	{
		printf("Incorrect number of agruements.\n");
		exit(1);
	}
	
	printf("The name of the program is %s\n", argv[0]);
//	Open each file and check for null pointers
	
	char Buffer[BSIZE];
	char Buffer1[BSIZE];

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
	
	while(!feof(infile))
	{
		fread(&data, sizeof(FileData), 1, infile);
		if(!feof(infile))
		{
			fprintf(outfile, "%d\n", data.a);
			fprintf(outfile, "%lf\n", data.b);
			fprintf(outfile, "%s", data.dataStr);
		}

	} 
	

	printf("The file has been converted and save to %s\n", Buffer1);
//	Close each file
	fclose(infile);
	fclose(outfile);
	return 0;

}
