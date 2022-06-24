#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t fret;
    fret = fork();
    if (fret > 0 )   //parent process.
    {
	printf("In the main process.\n");
	printf("The main process PID is:%d\n", getpid());
    }
    else if ( fret == 0)  //child process.
    {	
	printf("In the child process.\n");
	printf("The child process PID is:%d\n", getpid());
    }
}
