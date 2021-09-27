#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat s;	
	lstat(argv[1],&s);
	unsigned int m =s.st_mode;
	if(S_ISREG(m))
		printf("Regular File\n"); 
	else if(S_ISDIR(m))
		printf("Directory File\n"); 
	else if(S_ISCHR(m))
		printf("Character Device File\n");
	else if(S_ISBLK(m))
		printf("Block Device FIle\n");
	else if(S_ISFIFO(m))
		printf("FIFO (Named Pipe) File\n");
	else if(S_ISLNK(m))
		printf("Symbolic Link File\n");
	else if(S_ISSOCK(m))
		printf("Socket File\n");
	else
		printf("Invalid File");			

}
