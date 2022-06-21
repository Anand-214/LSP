#include<unistd.h>
#include<string.h>
void main()
{
    int len;
    int msg_len = 0;
    char buff[100];
    strncpy(buff,"This is my first system call.", 99);
    msg_len = strlen(buff);
    len = write(1, buff, msg_len);

}
