#include<unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h> 
int main()
{
	int fd=creat("file12.txt",0744);
	int f=fcntl(fd,F_GETFL);
	f=f&O_ACCMODE;
	printf("%d\n",f);
	if(f==0)
	printf("Read only");
	else if(f==1)printf("write only");
	else if(f==2)printf("read write only");
	else printf("other");

	
	/*
	Flag values-
	RDONLY = 0
	WRONLY = 1
	O_RDWR = 2
	O_ACCMODE = 3
	*/
}
