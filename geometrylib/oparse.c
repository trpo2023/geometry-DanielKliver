#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ERRORS.h"

char* readfile(char* string)
{
	FILE* file;
	file = fopen("fig.txt", "r");
	if(file == NULL)
	{
		int coder = 1;
		ERRORS(coder);
		return NULL;
	}
	string = malloc(sizeof(file)*sizeof(char)+1);
	while(!feof(file))
	{
		fgets(string, (sizeof(file)*sizeof(char)-1),file);
		
	}
	fclose(file);
	return string;

}
void trash(char* string)
{
	free(string);
}

void getdata(char *string)
{
	
	
		char sep [10]="(,) ";
		char *istr;
		istr = strtok (string,sep);
		while (istr != NULL)
		{
			printf ("%s",istr);
			istr = strtok (NULL,sep);
		}

	
}
