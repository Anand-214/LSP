#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
    pid_t pid;
    pid = fork();
    if ( pid == 0)
    {
	printf("Child Process.PID: %d\n", getpid());
        sleep(10);
	printf("Child terminated.\n");	
    }
    else if ( pid > 0)
    {
	printf("Parent Process.PID: %d\n", getpid());
        sleep(20);	
	printf("Parent child terminated.\n");	
    }
}
