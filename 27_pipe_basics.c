#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<string.h>
int main()
{
    int p[2];       //it will the array used for pipe.
    if ( pipe(p) == -1)   //pipe on failure returns -1 or else 0
    {
	printf("Pipe creation failed.\n");
    }
    switch (fork())   //for will return child pid 
    {
	case -1:
	    {
		perror("fork()");
		break;
	    }
	case 0 :
	    {
		printf("Child:Reading\n");
		close(p[1]);
		char buff[6];
		read(p[0], buff, 6);
		printf("%s\n", buff);
		break;
	    }
	default :
	    {
		close (p[0]);
		printf("Parent:");
		write(p[1], "Helllo.", 6);
		printf("Writing operation completed.\n");
		close(p[1]);
	    }
    }
}
