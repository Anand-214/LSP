#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int fd, sz;
    char buff[10];
    char *str_add = "Mohan";
    int len = strlen(str_add);
    fd = open("author.txt",O_WRONLY);
    if (fd < 0)
    {
	printf("File opening failed.");
    }
    sz = lseek(fd,84,SEEK_SET);
    strcpy(buff,str_add);
    sz = write(fd, buff, len);
    close(fd);
}
