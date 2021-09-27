/*This is 1st item from Hands on list 1
This will create soft link for /home/shwetank/Desktop/2021lab/fileabc.txt as
/home/shwetank/Desktop/shortcutfileabc.txt	*/

#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
void main()
{
    const char *src = "/home/shwetank/Desktop/2021lab/fileabc.txt";
    const char *dest = "/home/shwetank/Desktop/shortcutfileabc.txt";
    int x = symlink(src,dest);

    if(x==0)
    {
      printf("link created");
    }
    else
    {
      printf("some error");
    }
}

//To run this file, set cd to this directory where code exist then compile the code as folllows
//gcc 01a.c -o symlinkCreater.out		
//then run the code as follows
//	./symlinkCreator.out
//	./ means that we are looking for symlinkCreator.out in current working directory


//To create soft link using shell command in terminal use-
//	ln -s /home/shwetank/Desktop/2021lab/fileabc.txt /home/shwetank/Desktop/shortcutfileabc.txt

//To check whether file exist and a symlink use following command
//test -L shortcutfileabc.txt; echo $?
//echo $? shows the exit status. 0 for true and other numbers for false

