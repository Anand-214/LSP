#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#define MAX 500
int main()
{

    int shmid, num, dettach;
    key_t key;
    key = 'A';
    shmid = shmget(key, MAX, IPC_CREAT | 0664);
    if ( shmid < 0 )
    {
	printf("Error:\n%d", errno);
	exit(1);
    }
    printf("%d\n", shmid);
    int *ptr = shmat(shmid, NULL, 0);
    printf("Enter the number:");
    scanf("%d", &num);
    printf("The attach address is : %p\n", ptr);
    *ptr = num;
    printf("%d\n", *ptr);
    dettach = shmdt(ptr);
    if ( dettach == -1)
	printf("Dettach failed.\n");
    else
	printf("Dettached successfully.\n");
}
