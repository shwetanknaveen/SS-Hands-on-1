#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main() 
{
    int fd = open("file16.txt", O_RDWR);
    if(fd == -1) 
    {
      printf("Unable to open the file\n");
      exit(1);
    }
    static struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Before Read Lock:: \n");
    int ret = fcntl(fd, F_SETLKW, &lock);
    printf("After Read Lock::");
    getchar();
    lock.l_type = F_UNLCK;
    ret = fcntl(fd, F_SETLK, &lock);
    printf("After Read Unlock::");
}