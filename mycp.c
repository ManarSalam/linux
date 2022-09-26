#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <unistd.h>


int main(int argc, char *argv[])
{
    char buf[100];
    int fd1, fd2, Rcount =0;
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY | O_WRONLY | O_CREAT,0644);
   if(fd1 ==-1 || fd2 ==-1)
	  write(1,"Error\n",7);
   else
   { 
    while ((Rcount = read(fd1, buf, 100)) != 0) {
	write(fd2, buf, Rcount);
    }
   }

    close(fd1);
    close(fd2);
    return 0;
}
