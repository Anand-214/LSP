#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    pid = fork();
    switch (pid)
    {
	case 0 :
	    printf("In child.\n");
	    printf("PID: %d", getpid());
	    break;
	case -1 :
	    perror("fork");
	    break;
	default:
	    printf("Parent process.");
	    printf("%d\n", getpid());
	    break;
    }
}
