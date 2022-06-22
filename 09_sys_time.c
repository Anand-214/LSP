#include<stdio.h>
#include<time.h>
int main()
{
    time_t seconds,t;
   // seconds = time(&t);
    seconds = time(NULL);
    if (seconds == -1)
    {
	printf("Time operation failed.\n");
	return 1;
    }
    printf("The time in seconds from 1st Jan 1970 is : %ld",seconds);
 //   printf("The time in seconds from 1st Jan 1970 is : %ld",t);

}
