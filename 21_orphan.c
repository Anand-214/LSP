#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    pid_t pid;
    int i;
    pid = fork();
    if ( pid == 0)
    {
	printf("In child PID : %d\n",getpid());
	printf("In child PPID before: %d\n",getppid());
	sleep(10);
	printf("In child PPID after : %d\n",getppid());
	printf("Child terminated.\n");
    }
    else if ( pid > 0)
    {
	printf("In parent PID : %d\n", getpid());
	printf("Parent terminated.\n");
    }
}
