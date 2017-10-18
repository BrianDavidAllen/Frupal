#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str1[64];
	char *strptr = NULL; 
	char order[64];
	char orderNumber[64];
	char * webdata = getenv("QUERY_STRING");
	
	
	printf("Content-Type: text/plain ;charset=us-ascii\n\n");
	strcpy(str1, webdata);

	printf("%s\n", str1);
	
	strptr = str1;
	strptr=strtok(strptr,"=");

	while(strptr != NULL)
	{
		strcpy(order,strptr);
		printf("Item: %s\n",order);
		strptr=strtok(strptr+strlen(strptr)+1,"&");
		strcpy(orderNumber,strptr);
		printf("Count: %s\n",orderNumber);
		strptr=strtok(strptr+strlen(strptr)+1,"=");
	
	}
	
	return 0;
}
