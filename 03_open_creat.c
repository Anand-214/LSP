#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
    int fd;
    fd = open("newlog.txt",O_RDWR | O_CREAT, 0774);
    if (fd == -1)
    {
	printf("Failed with error number %d\n", errno);
    }
    else
    {
	printf("Success.");
    }
    close(fd);
}
