#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    printf("Program needs changes.\n");
    int fd;
    fd = open("redirect.txt", O_WRONLY);
  //  printf("%d\n",fd);
    close(1);
    int new_fd = dup(fd);
    printf("%d\n",new_fd);
    printf("redirected to this file.");
    close(fd);
   // int new_fd2 = dup2(new_fd, 1);
   // printf("%d", new_fd2);
//    fopen(stdout,"/dev/null");
    printf("Hello world.");

}
