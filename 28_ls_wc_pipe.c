#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
int main()
{
    int p[2], fd, fret, rret, wret;
    if (pipe(p) == -1)
	printf("Pipe failed.\n%s", strerror(errno));
    fret = fork();
    if (fret > 0)
    {
	printf("Prent process to write to the pipe.\n");
	close(p[0]);
	dup2(p[1], 1);
	execl("/bin/ls","ls",(char*)NULL);
    }
    else if (fret == 0)
    {
	close(p[1]);
	dup2(p[0], 0);
	execlp("wc","wc", (char*)NULL);
    }
    else
	printf("Fork failed.\n%s",strerror(errno));
    
}
