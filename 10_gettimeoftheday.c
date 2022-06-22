#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include<fcntl.h>
#include<time.h>
int main()
{

    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
    {
	printf("Operation failed.");
	exit(1);
    }
    printf("The time in seconds:%ld\n", tv.tv_sec);
    printf("The time in seconds:%ld\n", tv.tv_usec);
}
