#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
int main()
{
    int sz, fd;
    char buf[100];
    strcpy(buf, "These lines will be added to the file.\n");
    fd = open("new_file.txt", O_WRONLY | O_APPEND);
    if (fd < 0)
    {
	printf("ERROR: %d", errno);
	exit(1);
    }
    sz = write(fd, buf, strlen(buf));
    printf("The characters writeen are : %d", sz);
    close(fd);
}
