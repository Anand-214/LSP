#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#define my_fifo1 "/tmp/p2"
int main()
{
    int fd, lret;
    fd = open(my_fifo1, O_RDWR);
    if ( fd == -1)
	printf("Open failed.\n%s\n", strerror(errno));
    else
    {
	int buff[10];
	read(fd,(int*)buff,10);
	printf("The content of named pipe is: %d\n", *buff);
    }
}
