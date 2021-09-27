#include<unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h> 
int main()
{
	char c;
	int fd=open("/home/shwetank/Desktop/2021lab/fileabc.txt",O_RDONLY);
	while(read(fd,&c,1))
	{
		if(c=='\n')
		printf("\nNew Line detected!");	
		else
		printf("%c",c);
		//See this program in gg's code
	}
	
}
