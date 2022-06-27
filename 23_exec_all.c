#include<sys/stat.h>     //new program in the same process.
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main(int argc, char* argv[])
{
    printf("PID before exec(): %d\n", getpid());
/*  
    execl("/bin/ls","ls","-l",(char*)NULL);
    execlp("cat","cat","16_system.c",(char*)NULL);
    execv("/bin/cat",argv);
*/
    execvp("cat",argv);
    printf("Hi exec()\n");
}
