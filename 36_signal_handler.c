#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void signal_handler (int);
int count = 0;
int main()
{
    printf("Enter ctrl + C\n");
    signal(SIGINT, signal_handler);
  //  while(1);
    pause();
    printf("BYE.\n");
}
void signal_handler(int num)
{

    printf("number: %d\n", num);
    printf("You pressed ctl+C : %d\n", count++);
    if (count == 6)
	signal(SIGINT, SIG_DFL);
}
