#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char * protocolString = 0;
	char length[160];

	printf("Content-Type: text/plain;charset=us-ascii\n\n");

	strncpy(length, getenv("CONTENT_LENGTH"),159);
	int len = atoi(length);
	protocolString = malloc(len + 1);
	fgets(protocolString, len + 1, stdin);

	printf("%s\n", protocolString);


	free(protocolString);
	return 0;
}
