#include <stdio.h>
#include <string.h>
#include <cgi.h>

char name[20];
s_cgi *cgi;

void main(void)
{
	cgi = cgiInit();
	
	strcpy(name,cgiGetValue(cgi, "p"));

	printf("Content-Type: text/html;charset=us-ascii\n\n");
	printf("<h1>%s</h1>\n,name);
}
