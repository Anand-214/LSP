#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
int main()
{
    int count = 0;
    int p[2];
    while(1)
    {
	if (pipe(p) == -1)
	{
	    printf("No. of pipes:%d", count);
	    printf("Pipe creation failed.\n%s", strerror(errno));
	    exit(EXIT_FAILURE);
	}
	count++;
	printf("p[0] : %d\n,p[1] : %d\n",p[0], p[1]);
    }
}
