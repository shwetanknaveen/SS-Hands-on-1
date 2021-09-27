#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{
	const char *src = "/home/shwetank/Desktop/2021lab/fileabc.txt";
	const char *dest = "/home/shwetank/Desktop/hardLinkFile.txt";
	int status=link(src,dest);
	if(status == 0 )
	printf("\n Hard link for file has been created\n");
	else
	printf("\n Hard link creation failed\n");

	//ln file1.txt hardlink_file1
}

//To run this file, set cd to this directory where code exist then compile the code as folllows
//gcc 01b.c -o hardLinkCreater.out		
//then run the code as follows
//	./symlinkCreator.out
//	./ means that we are looking for symlinkCreator.out in current working directory

//	shell comand
//	ln /home/shwetank/Desktop/2021lab/fileabc.txt /home/shwetank/Desktop/shortcutfileabc.txt

//To check whether file exist and a symlink use following command
//test -L shortcutfileabc.txt; echo $? 
//echo $? shows the exit status. 0 for true and other numbers for false

