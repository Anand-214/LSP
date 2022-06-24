#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    fork();
    fork();
    fork();
    int cpid = wait(NULL);
    if ( cpid == -1)
	printf("Hello.\n");
}
