#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{
	int fd1=open("/home/shwetank/Desktop/2021lab/fileabc.txt",O_RDONLY);
	int fd2=open("/home/shwetank/Desktop/2021lab/fileabcCOPY.txt",O_WRONLY);
	char c;
	while(read(fd1,&c,1))//reading character by character and it will return 0 at the end of the file
	{
		write(fd2,&c,1);	
	}
	printf("\nFile copying completed!");
}
