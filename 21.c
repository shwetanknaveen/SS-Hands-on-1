#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	int f=fork();
	if(f==0)
	{
        printf("\nIn child process\n");
		printf("\nChild's Process ID:: %d\n",getpid());
		printf("\nParent's Process ID fetched in child process:: %d\n",getppid());
	}
    else
    {
        printf("\nParent's Process ID:: %d\n",getpid());
    }
}