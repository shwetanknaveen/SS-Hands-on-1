#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{
	int fd=creat("file10.txt",0644);
	char buff[]="0123456789";
	write(fd,buff,10);
	int ret=lseek(fd,20,SEEK_CUR);//20 bytes from current position
	write(fd,buff,10);
	printf("lseek returns:: %d\n",ret);

	//od -c file10.txt
	//od means octal dump for the file. -c will change the octal value to characters. First column will give byte offset i.e, no. of 
	//bytes that has been written upto this point
	
	/*
	If we are at 10th position and offset = 2
	
	whence		new position 
	SEEK_SET	2
	SEEK_CUR	10+2 = 12
	SEEK_END	sizeoffile+2
	*/
}
