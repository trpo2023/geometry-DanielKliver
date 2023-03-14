#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readfile(char* string)
{
	FILE* file;
	file = fopen("fig.txt", "r");
	string = malloc(sizeof(file)*sizeof(char)+1);

	while(!feof(file))
	{
		fgets(string, 10000,file);
	}
	fclose(file);
	return string;
	free(string);

}

void getdata(char *string)
{
	char sep [10]="(,)";
	char *istr;
	istr = strtok (string,sep);
	while (istr != NULL)
	{
		printf ("%s\n",istr);
		istr = strtok (NULL,sep);
	}

}

int main()
{
	char* string = NULL;
	string = readfile(string);
	getdata(string);
	return 0;
}
