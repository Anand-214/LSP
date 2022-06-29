#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define my_fifo1 "/tmp/p2"
int main()
{
    int fd, pp, pk;
    mkfifo(my_fifo1, 0666);
    printf("fifo created successfully.\n");
    fd = open(my_fifo1, O_WRONLY);
    if (fd == -1)
    {
	printf("Opening file failed.\n");
	exit(1);
    }
    else 
    {
	pp = 100;
	write(fd, &pp, sizeof(pp));
	pk = 200;
	write(fd, &pk, sizeof(pk));
	exit(0);
	close(fd);

    }
}


