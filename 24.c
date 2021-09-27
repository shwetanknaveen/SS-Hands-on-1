#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{  
	int pid = fork(); 
	if (pid > 0) 
	{
		printf("In Parent Process. Parent Process ID:: %d\n",getpid());
	} 
	else if (pid == 0) 
	{  
		printf("\nIn Child Process. Child Process ID:: %d and Parent Process ID:: %d\n",getpid(),getppid());
		sleep(2);//when child process is sleeping, parent process will finish its execution and child becomes orphan
		printf("\nIn Child Process,when child has woken up after sleeping, its parent Process ID:: %d\n",getppid());
	} 
	return 0;
}
/*
orphan process should get ppid as pid of init process that is 1 but here when we are executing this code on GNOME terminal
orphan process would be adopted by init --user
https://unix.stackexchange.com/questions/194182/orphan-processs-parent-id-is-not-1-when-parent-process-executed-from-gnome-term
*/