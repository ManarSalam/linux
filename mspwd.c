#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#define INIT_SIZE 3

int main(int argc, char *argv[])
{
    char *ret = 0;
    char *pathbuf;
    int size = INIT_SIZE;
    pathbuf = (char *) malloc(size);
    ret = getcwd(pathbuf, size);
    while (ret == 0) {
	size += 10;
	pathbuf = realloc(pathbuf, size);
	ret = getcwd(pathbuf, size);
    }
    strcat(pathbuf,"\n");
    ret=(char*) write(1, pathbuf, size);
    if(ret==(char*)-1)
    ret=(char*) write(1, "Error to write the path", 18);
    
    free(pathbuf);
    return 0;
}
