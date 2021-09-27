#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{
	int fd1=creat("file11.txt",0744);
	char buff1[]="abcde";
	char buff2[]="01234";
	char buff3[]="fghij";
	char buff4[]="56789";
	char buff5[]="klmno";
	
	write(fd1,buff1,5);
	
	int fd2=dup(fd1);//dup() assigns lowest available file descriptor value. Now fd1 and fd2 will point to the same file
	
	write(fd1,buff2,5);
	write(fd2,buff3,5);
	
	int fd3=12;
	dup2(fd1,fd3);//in dup2() with second parameter we mention that what should be the value of duplicate file descriptor
			//fd1 will be duplicated to fd3 and now fd1 and fd3 will point to the same files
			//if the value of fd3 was already assigned somewhere thenn it will be closed and used here
	
	write(fd1,buff4,5);
	write(fd3,buff5,5);
	
	//We can find the details about which fd for this process is pointing to which file. We get pid of process by command-
	// pidof ./11.out
	//then ls -l /proc/pid"which was found"/fd
	
	
	//for fcntl fun() see man 2 fcntl
	
	
}
