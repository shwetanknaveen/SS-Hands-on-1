#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{
	char buff[15];
	read(0,buff,15);//first parameter is file descriptor.Here we are reading from stdin hence it's 0. Second one is buff into which
			//we are reading and third parameter is the size that how much we are reading
	write(1,buff,sizeof(buff));//first parameter is file descriptor.Here we are wrting to stdout hence it's 1.
					//Second one is buff from which
					//we are writing and third parameter is the size that how much we are writing
}
