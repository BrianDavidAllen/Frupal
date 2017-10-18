#include <stdio.h>
#include <string.h>
#include <cgi.h>
#include <stdlib.h>

char burgers[80];
char hotdogs[80];
s_cgi *cgi;

int main(void)
{
	cgi = cgiInit();

	strcpy(burgers, cgiGetValue(cgi, "burgNum"));
	
	int burgs = atoi(burgers);
	
	strcpy(hotdogs, cgiGetValue(cgi, "hotDogNum"));
	
	int dogs = atoi(hotdogs);

	int total = 2 * burgs + dogs;

	printf("Content-Type: text/html;charset=us-ascii\n\n");
	printf("<h1>Number of Burgers: %s</h1>", burgers);
	printf("<h1>Number of Dogs: %s</h1>", hotdogs);
	printf("<h1>Order Total: %d</h1>", total);
}
