#include <stdio.h>
	/*
void getData(const char * s_)
{
	char * s = _strdup(s_); // Чтоб можно было strtok пользовать
	for(char * c = strtok(s,"}"); c; c = strtok(NULL,"}"))
	{
		char s1[128]; int a[4];
		sscanf(c,"%*[^']'%[^']%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d",s1,&a[0],&a[1],&a[2],&a[3]);
		printf("%s %d %d %d %d\n",s1,a[0],a[1],a[2],a[3]);
	}
	free(s);
}
*/
int main()
{
	FILE *file;
	char string[1000000];
	file = fopen("fig.txt", "r");
	while(!feof(file))
	{
		if(fgets(string, sizeof(string),file) != NULL)
		{
		printf("%s", string);
		}
	}
	fclose(file);
	return 0;
}
