/*
 * Saad Arshad 00857432
 * CS 262, Lab Section 208
 * Lab 2
 */

#include <stdio.h>
#include <stdlib.h>
#define BSIZE (100)

double getAGI(double, char[]);
int getTaxr(int , char[]);
double getNetIncome(double, int);
int main()
{
	char Buffer[BSIZE];
	int taxrate = 0;
	double agi = 0.0;
	double neti = 0.0;
	
	printf("Hello and welcome to your tax calculator\n");
	agi = getAGI(agi , Buffer);
	taxrate = getTaxr(taxrate , Buffer);

	printf ("Your AGI is %.2lf and your taxrate is %d\n ", agi, taxrate);
	printf("Now calculating your net income after paying taxes\n");
	neti = getNetIncome(agi , taxrate);
	
	printf("Your net income after taxes is %lf\n ",neti);
	
	

}

double getAGI(double agi, char Buffer[])
{

	printf("Please enter your AGI first to begin\n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer,"%lf" , &agi);
	if(agi < 0)
	{
		printf("You can not put a negative number\n");
		exit(1);
	}
	return agi;
}

int getTaxr(int taxrate, char Buffer[])
{
	printf("Enter taxrate in whole number\n");
	fgets(Buffer, BSIZE, stdin);
	sscanf(Buffer, "%d", &taxrate);
	if(taxrate < 0)
	{
		printf("you can not put a negative number\n");
		exit(1);
	}
	return taxrate;
}

double getNetIncome(double agi, int taxrate)
{
 return agi - ((taxrate/100.0) *agi);		
}
