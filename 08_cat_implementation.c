#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    int lret,fd, rret, wret;
    if ( argc == 2)
    {
	fd = open(argv[1], O_RDONLY);
	lret = lseek(fd, 0, SEEK_END);
	//    printf("%d\n", lret);
	lseek(fd,0,SEEK_SET);
	char buff[lret];
	if (fd == -1)
	{
	    printf("Opening file failed.\n%s", strerror(errno));
	    exit(1);
	}
	rret = read(fd,buff,lret);
	if (rret == -1)
	{	
	    printf("Read failed.\n%s", strerror(errno));
	    exit(1);
	}
	wret = write(1,buff,rret);
	if (wret == -1)
	{
	    printf("writing to stdout failed.\n%s", strerror(errno));
	}
	close(fd);
    }
    else
	printf("Please pass file name in CLA.\n");
}

