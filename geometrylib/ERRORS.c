#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ERRORS(int coder)
{
	switch(coder){
		case 1:
			printf("Failed to open file\n");
			break;
		default:
			printf("Ok\n");
	}
	return -1;
}
