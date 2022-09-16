#include <stdio.h>
#include <string.h>

int main()
{
char text[150];

printf("Sada S000t test keda > ");
while(1)
{
	fgets(text,sizeof(text),stdin);
	if(strcmp(text,"exit\n")!=0)
	{	
	   printf("You said: %s",text);
	   printf("Sada S000t test keda > ");
	}
	else
	{
		printf("Good Bye :) \n");
		break;
	}
}
return 0;
}

