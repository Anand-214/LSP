#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#define my_fifo1 "/tmp/p1"
int main()
{
    int fd;
    char buff[6];
    if ((fd = open(my_fifo1, O_RDWR)) < 0)
	printf("Open failed.");
    read(fd,buff,6);
    printf("Message is %s\n", buff);
}

