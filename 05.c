#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include<string.h>
int main()
{
	int fd[5];
	int count = 0;
	char path[50];
	while(1)
	{
		if(count == 5)
			break;
		sprintf(path,"/home/shwetank/Desktop/fileNo%d.txt",count+1);//it's used to alter and store string
		fd[count] = creat(path,0744);
		count++;

		
	}
	while(count>=0)
	{
	if(fd[count-1]!=-1)
	printf("\nFile descriptor for file no %d is %d \n",count,fd[count-1]);
	else
	printf("File no %d is not created \n",count);
	count--;
	}
	while(1)
	{
	//just to keep the process running
	}
	
/* we can view informations in proc directory like 
While mentioning / in the first place, / is the root
	cat /proc/cpuinfo 		it shows cpu information
	ll /proc/pid/fd		it shows all the information related to all the file descriptors attached to this process
	NOTE -> Process should be runnig which can be done using putting an infinite while loop so that we can view its information using above commands
	
	*/
}
