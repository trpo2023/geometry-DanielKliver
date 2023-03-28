#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct Circle
{
	char *name;
	double y;
	double x;
	double diameter;
	double square;
	double perimeter;

};
int ERRORS(int errorcode)
{
	switch(errorcode)
	{
		case 1:
			printf("Не удалось открыть файл\n");
			return -1;
		case 2:
			printf("Не удалось записать файл\n");
			return -1;
		case 3:
			printf("Неправильное название фигуры\n");
			break;
		case 4:
			printf("Нет открывающей скобки\n");
			break;
		case 5:
			printf("Закрывающей скобки нет или она расположена не в том месте\n");
			break;
		case 6:
			printf("Нет запятой\n");
			break;
		case 7:
			printf("Неправильное имя\n");
			return -1;
		default:
			printf("Неверный код ошибки\n");
	}
	return 0;
}
void strlower(char* string)
{
	for(int i = 0; i<strlen(string); i++)
	{
		string[i] = tolower(string[i]);
	}

}
int* getdatacircle(char* string, int countfig, struct Circle *circle)
{
	if(string[0] == 'c' || string[0] == 't')
	{
		if(string[0] == 'c')
		{
			if(string[5] == 'e')
			{
				circle[1].name = "circle";
			}
			else
			{
				int errorcode = 7;
				ERRORS(errorcode);
			}
		}
	}
	else
	{
		int errorcode = 3;
		ERRORS(errorcode);
	}
	int point = 6;
	int rock = 0;
	char save[rock];
	while(string[point] == ' ')
	{
		point++;
	}
	while(string[point] != ' ')
	{
		if(string[point] == '(')
		{
			point++;
		}
		else
		{
			int errorcode = 4;
			ERRORS(errorcode);
		}
		save[rock] = string[point];
		rock++;
		point++;
	}
	circle[countfig].x = atof(save);
	while(string[point] == ' ')
	{
		point++;
	}
	if(string[point] == ',')
	{
		int errorcode = 6;
		ERRORS(errorcode);
	}
	rock = 0;
	char savex[rock];
	while(string[point] != ' ')
	{
		if(string[point]==',')
		{
			break;
		}
		savex[rock] = string[point];
		rock++;
		point++;
	}
	circle[countfig].y = atof(savex);
	while(string[point] == ' ')
	{
		point++;
	}
	if(string[point] == ',')
	{
		point++;
	}
	else
	{
		int errorcode = 6;
		ERRORS(errorcode);
	}
	while(string[point] == ' ')
	{
		point++;
	}
	rock = 0;
	char savediam[rock];
	while((string[point] != ' ')&&(string[point]!=')'))
	{
		savediam[rock] = string[point];
		rock++;
		point++;
	}
	if(string[point] != ')')
	{
		int errorcode = 5;
		ERRORS(errorcode);
	}
	circle[countfig].diameter = atof(savediam);
	circle[countfig].square = (3.14*(circle[countfig].diameter/2)*(circle[countfig].diameter/2));
	circle[countfig].perimeter = (2*3.14*(circle[countfig].diameter/2));
	return 0;
}
int readfile(char* string, struct Circle *circle, int countfig)
{
	FILE* file = fopen("fig.txt", "r");
	if(file == NULL)
	{
		int errorcode = 1;
		ERRORS(errorcode);
	}
	string = malloc(1000000);
	if(string == NULL)
	{
		int errorcode = 2;
		ERRORS(errorcode);
	}
	while(fgets(string, sizeof(string)*sizeof(char)+500, file)!=NULL)
	{
		strlower(string);
		printf("%s", string);
		getdatacircle(string, countfig, circle);
		countfig++;
	}
	fclose(file);
	return countfig;
}
void conclusion(struct Circle *circle, int countfig)
{
	for(int i = 0; i<countfig; i++)
	{
		printf("\n\nCircle %d:\n", i+1);
		printf("Point: x - %f, y - %f\n", circle[i].x, circle[i].y);
		printf("Diameter: %f\n", circle[i].diameter);
		printf("Square: %f\n", circle[i].square);
		printf("Perimeter: %f\n", circle[i].perimeter);
	}
}
int main()
{
	char* string = NULL;
	struct Circle circle[50];
	int countfig = 0;
	countfig = readfile(string, circle, countfig);
	conclusion(circle, countfig);
	return 0;
}
