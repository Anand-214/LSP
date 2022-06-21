#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main()
{
    int fd;
    fd = open("new_file.txt", O_WRONLY);
    if (fd == -1)
    {
	printf("Open file failed. Error number : %d", errno);
    }
    else
    {
	printf("Open file success.");
    }
    close(fd);
}
