#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
int main()
{
    int retfifo,fd1,rret;
    char arr1[50];
    char* myfifo = "/tmp/op";
    retfifo = mkfifo(myfifo, 0666);
    if (retfifo == 0 )
    {
	printf("Fifo created successfully.\n");
	fd1 = open(myfifo, O_RDONLY);
	rret = read(fd1,arr1,strlen(arr1));
	printf("read characters:%d\n", rret);
	printf("%s\n",arr1);
	system("rm /tmp/op");
	close(fd1);
    }
    else
    {
	printf("%d\n", retfifo);
	printf("fifo not created.\n%s",strerror(errno));
    }
}
