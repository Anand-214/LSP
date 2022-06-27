#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
int main()
{
    pid_t pid;
    int fd,lret,lret1,rret,wret;
    printf("parent PID:%d\n",getpid());
    pid = fork();
    if (pid > 0)
    {
	printf("In parent process,PID:%d\n",getpid());
	fd = open("new.txt", O_RDONLY);
	if (fd == -1)
	{
	    printf("File opening failed,%s\n", strerror(errno));
	    exit(1);
	}
	lret = lseek(fd,0,SEEK_END);
	lret1 = lseek(fd,0,SEEK_SET);
	char buff[lret];
	rret = read(fd, buff,lret);
	wret = write(1,buff,rret);
    }
    else if (pid == 0)
    {
	printf("In child process,PID:%d\n",getpid());
	execl("/bin/ls","ls","-ls","new.txt",(char*)NULL);
    }
    close(fd);
}


