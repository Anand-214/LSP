#include"header.h"
void fun1()
{
    int len;
    int msg_len = 0;
    char buff[100];
    strncpy(buff, "This is a write system call executed from fun1.\n", 99);
    msg_len = strlen(buff);
    len = write(1, buff, msg_len);
}
