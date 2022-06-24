#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("new.txt",O_RDONLY);
    if ( fd == -1)
    {
	printf("File opening failed.");
	exit(1);
    }
    char my_str[] = "Failed fstat"; 
    struct stat file_info;
    if (fstat(fd, &file_info) == -1)
    {
	write (1,my_str,strlen(my_str));
    }
    printf("file permissions :%u", file_info.st_mode);
    close(fd);
}

