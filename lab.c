#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char protocolString[160];
	
	printf("Content-Type: text/html;charset=us-ascii\n\n");

	strncpy(protocolString, getenv("QUERY_STRING"), 159);
	
	printf("<h1>%s</h1>",protocolString);

	return 0;
}
