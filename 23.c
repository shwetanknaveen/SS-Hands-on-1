#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{  
	int pid = fork(); 
	if (pid > 0) 
	{
		while(1);//parent will no sleep and wait to get the child exit status neither parent is getting finished hence child
            //will finish execution but since its exit status won't be read by parent hence it will remain there as zombie
		//parent reads child exit status at the end of its (parent) execution
            //  https://www.geeksforgeeks.org/zombie-and-orphan-processes-in-c/
	} 
	else if (pid == 0) 
	{  
		printf("\nIn Child Process. Child Process ID %d\tCheck through ps aux | grep 'Z' for zombie processes\n",getpid());
		printf("\nChild Process Has Stopped Execution.\n");

	} 
	return 0;
}
