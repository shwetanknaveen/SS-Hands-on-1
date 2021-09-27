#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{
    //fork returns 0 for the child process and pid of child for parent process
	int p1=fork();//parent will create child process
	int p2=fork();//parent and child created in above state will create child proceses
	if(p1>0 && p2>0)//in parent process
	{
		printf("Parent Process ID:: %d and waiting for:: %d\n",getpid(),p2);
		int pid=waitpid(p2);
		printf("Parent Process ID:: %d after waiting for:: %d\n",getpid(),pid);
	}
	else
	{
		if(p2==0)
		{
			printf("Child Process ID for p2=0:: %d\n",getpid());
			sleep(5);
		}
		else
		{
			printf("Child Process ID:: %d\n",getpid());
		}
	}
}
/*

                                      p1=0
                                p2>0(=pid of gch1)             p2=0
parent-------------------------------->ch1-------------------->gch1
    |
    |
    ---------------------------------->ch2
p1>0(=pid of ch1)                     p2=0      
p2>0(=pid of ch2)

*/