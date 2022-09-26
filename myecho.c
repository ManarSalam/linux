#include<stdio.h>
#include <unistd.h>



int main(int argc, char *argv[])
{
    int count = 0;
    int i = 1, j = 0;
    while (argv[i] != "\0") {
	while (argv[i][j] != '\0') {
	    count++;
	    j++;
	}
	j = 0;

	write(1, argv[i], count);
	write(1, " ", 1);
	i++;
	if (i == argc)
	    break;

	count = 0;
    }
    write(1, "\n", 1);
}
