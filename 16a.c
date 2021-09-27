#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
//#include <conio.h>
int main() 
{
    int fd = open("file16.txt", O_RDWR);//Here O_CREAT is not set hence if file doesn't exist then it won't create it
    if(fd == -1) 
    {
      printf("Unable to open the file\n");
      exit(1);
    }
    static struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = 0;//offset value
    lock.l_whence = SEEK_SET;//where to add the offset
    lock.l_len = 0;//Size of lock area. 0 means lock has to be until EOF
    lock.l_pid = getpid();
    printf("Before Write Lock:: \n");
    int ret = fcntl(fd, F_SETLK, &lock);//it will return -1 if the lock coudn't be accquired
    /*If you prefer fcntl not to block if the call cannot get the lock you requested, use F_SETLK instead of F_SETLKW.
     If the lock cannot be acquired, fcntl returns –1 immediately.*/

    if(ret!=-1) printf("\nLock acquired through code 16a.c");
    else{
        printf("\nLock coudn't be acquired through code 16a.c");
        if(getchar())
        exit(EXIT_FAILURE);
    }
    while(1)
	{
        if(getchar())
            break;
    }
    lock.l_type = F_UNLCK;
    ret = fcntl(fd, F_SETLKW, &lock);
    printf("\nLock released through 16a.c \n");
}

/*
use following command on terminal to create the file file16.txt in the directory where this code is
touch file16.txt
*/