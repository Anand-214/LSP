#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

int main()
{
    int fd, sz = 0;
    char buzz[100];
    fd = open("new_file.txt",O_RDWR);
    if (fd < 0 )
    {
	printf("Failed file open.");
    }
    sz = lseek(fd, 0, SEEK_SET);
    printf("The current position of lseek is :%d\n", sz);

    sz = lseek(fd, 2, SEEK_SET);
    printf("The current position of lseek is :%d\n", sz);
   
    sz = lseek(fd, 10, SEEK_CUR);
    printf("The current position of lseek is :%d\n", sz);

    sz = lseek(fd, 10, SEEK_CUR);
    printf("The current position of lseek is :%d\n", sz);
    
    sz = read(fd, buzz, 15);
    printf("The lines read are :%s\n", buzz);
    
    strcpy(buzz, "We will append a new line here.");
    write(fd, buzz, strlen(buzz));

    sz = lseek(fd,0,SEEK_SET);
    sz = read(fd, buzz, 80);
    printf("The read bytes are %d\nThe content is : %s", sz, buzz);
    close(fd);
}
