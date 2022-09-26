#include <stdio.h>
#include<string.h>

#include <sys/types.h>
#include <unistd.h>

#include <sys/stat.h>
#include <fcntl.h>



int main(int argc, char *argv[])
{
    char *pathname = argv[2];
    char buf[100];
    int fd1, fd2, Rcount = 0;

    fd1 = open(argv[1], O_RDONLY);
    strcat(pathname, argv[1]);
    fd2 = open(pathname, O_RDONLY | O_WRONLY | O_CREAT,0644);
    printf("%s\n\n", pathname);

    while ((Rcount = read(fd1, buf, 100)) != 0) {
	write(fd2, buf, Rcount);
    }


    close(fd1);
    close(fd2);
//printf("%s\n",pathname);
    int ret = 0;
    ret = remove(argv[1]);


}
