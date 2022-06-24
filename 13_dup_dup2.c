#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd, fd1;
    fd = open("new.txt", O_RDONLY);
    if (fd == -1)
    {
	printf("Failed open.\n");
	printf("Error code: %d\n", errno);
	printf("%s\n", strerror(errno));
	exit(1);
    }
    close(0);
    int num = dup(fd);
    if (fd == -1)
    {
	printf("dup failed.\n");
	printf("Error code: %d\n", errno);
	printf("%s\n", strerror(errno));
	exit(1);
    }
    printf("%d",num);


}
