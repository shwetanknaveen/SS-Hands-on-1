#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{
	int fd=creat("file3.txt",0744);
	printf("File Descriptor After creat():: %d\n",fd);
}
