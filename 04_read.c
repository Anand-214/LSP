#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
    int fd, sz;
    char buf[20] = {0};
    fd = open("new_file.txt", O_RDONLY);
    if (fd < 0)
    {
	printf("File opening failed.\nError number: %d\n",errno);
	exit(1);
    }
    sz = read (fd, buf, 10);
    printf("call 1 - called read, fd = %d\n%d bytes were read.\n",fd, sz);
    printf("Read bytes are as follows: \n<%s>\n", buf); 
    close(fd);
}
