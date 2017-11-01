#include <stdio.h>
#include <string.h>
#include <cgi.h>
#include <stdlib.h>

char burgers[80];
char hotdogs[80];
char name[80];
s_cgi *cgi;

int main(void)
{
	cgi = cgiInit();

	//copys the value passed from javascript
	//into a c variable
	strcpy(burgers, cgiGetValue(cgi, "burgNum"));
	
	int burgs = atoi(burgers);

	//copys the value passed in hotDogNum from 
	//a javascript code block into a c variable 'hotdogs'	
	strcpy(hotdogs, cgiGetValue(cgi, "hotDogNum"));

	strcpy(name, cgiGetValue(cgi, "customerName"));
	
	int dogs = atoi(hotdogs);

	int total = 2 * burgs + dogs;

	printf("Content-Type: text/html;charset=us-ascii\n\n");
	if(name != "")
		printf("<h2>Thanks %s</h2>", name);
	else
		printf("<h2>Thanks</h2>");
	printf("<p>Number of Burgers: %s</p>", burgers);
	printf("<p>Number of Dogs: %s</p>", hotdogs);
	printf("<p>Order Total: $%d</p>", total);
}
