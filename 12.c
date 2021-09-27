#include<unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h> 
int main()
{
	int fd=creat("file12.txt",0744);
	int f=fcntl(fd,F_GETFL);
	printf("%d",f);
	
	/*
	Flag values-
	RDONLY = 0
	WRONLY = 1
	O_RDWR = 2
	O_ACCMODE = 3
	*/
}
