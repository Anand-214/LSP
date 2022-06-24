#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>
#include<fcntl.h>
int arr[2];
char buff[] = "anand";
pid_t fret;
int wret, rret;
int main()
{
    int fd;
    char* new_buffer[strlen(buff)];   //new buffer to read the same content as in buff after writing.
    int piperet = pipe(arr);
    if (piperet == 0)
	printf("Pipe creation successfull.\n");
    else 
    {
	printf("Pipe creation failed.\n");
	exit(1);
    }
    fret = fork();
    if ( fret > 0 )
    {
	printf("(fret)returning pid of the child process to parent : %d\n", fret);
	printf("parent pid using getpid: %d\n", getpid());
	printf("We are in the parent process.");
	wret = write(arr[1], (char*) buff, strlen(buff));
	if ( wret == -1)
	{
	    printf("write failed.\n");
	    exit(1);
	}
	printf("%d\n", wret);
    }
    else if ( fret == 0)
    {
	printf("Child process id : %d\n", getpid());
	printf("We are in child process.\n");
	rret = read (arr[0], (char*)new_buffer, 5);
	printf("rret : %d\n",rret);
	printf("The new buffer is : %s\n", (char*)new_buffer);
    }
}
