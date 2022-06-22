#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
    int fd, fd1;
    char buff[50];
    int ret;
    fd = open("read.txt",O_RDONLY);
    fd1 = open ("write.txt", O_WRONLY | O_CREAT, 0777);
    do
    {
	ret = read (fd, buff, 50);
	write (fd1,buff, 50);
    }while(ret != 0 );
    close(fd);
    close(fd1);
}
