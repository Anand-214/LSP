#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#define MAX 100
int main()
{

    int shmid, num, dettach;
    key_t key;
    int* ptr;
    key = 'A';
    shmid = shmget(key, MAX, 0664);
    if ( shmid < 0 )
    {
	printf("Creating shared memory failed.\n%s", strerror(errno));
	exit(1);
    }
    printf("%d\n", shmid);
    ptr = shmat(shmid, NULL, 0);
    if (ptr < 0)
    {
	perror("shmat");
	exit(1);
    }
    //*ptr = num;
    printf("Value for the shared memory: %d\n", *ptr);
    dettach = shmdt(ptr);
    if (dettach == -1)
	perror("shmdt");
    else
	printf("Dettach Successfull.");
    shmctl(shmid,IPC_RMID,NULL);
}
