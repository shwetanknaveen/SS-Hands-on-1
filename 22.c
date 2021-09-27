#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	int fd=creat("file22.txt",0744);
	char buff1[]="\nParent process is writing this";
	char buff2[]="\nChild process is writing this";
	int f=fork();
	if(f==0)
	{
		write(fd,buff1,sizeof(buff1));
	}
	else
	{
		write(fd,buff2,sizeof(buff2));
	}
}