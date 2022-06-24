#include<stdio.h>
  int main()
    {
	printf("%d\n",getpid());
	if(fork()!=0)
	    printf("%d\n",getpid());
	else
	    printf("%d\n",getpid());

}
