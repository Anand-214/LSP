#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/types.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
int fiforet;
char* myfifo = "/tmp/op";
char arr[] = "Hi this is my first named pipe.";
int main()
{
    int fd,wret;
    fiforet = mkfifo(myfifo, 0666);
    if ( fiforet == 0)
    {
	printf("fifo success.\nSender executed\n");
	fd = open(myfifo,O_WRONLY);
	wret = write(fd,(char*)arr,strlen(arr));
	if (wret == -1)
	{
	    printf("Writing failed.\n%s",strerror(errno));
	}
	printf("Written characters:%d\n", wret);
	system("rm /tmp/op");
	close(fd);
    }
    else
	printf("fifo not created, %s",strerror(errno));
}
