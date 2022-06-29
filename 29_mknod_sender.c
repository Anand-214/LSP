#include<stdio.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#define my_fifo1 "/tmp/p1"
int main(int argc, char* argv[])
{
    int fd;
    if (mknod(my_fifo1, S_IFIFO | 0666, 0) < 0)
    {
	perror("my_fifo1");
	exit(1);
    }	
    if ((fd = open(my_fifo1, O_RDWR)) < 0)
    {
	printf("Opening failed.");
    }
    write(fd, "Hello", 6);
 	   return 0;    
}
