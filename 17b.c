#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main() 
{
    int fd = open("file17", O_RDWR);
    if(fd == -1) 
    {
      printf("Unable to open the file\n");
      exit(1);
    }
    struct ticket
    {
        int tno;
    } t;

    static struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;//now start =0 and whence = seek_set hence lock area will start from 0
    lock.l_len = 0;//0 means lock will be until end of the file
    lock.l_pid = getpid();

    printf("Before Write Lock:: \n");
    int ret = fcntl(fd, F_SETLKW, &lock);//ret=-1 if lock couldn't be acquired
    read(fd,&t,sizeof(t));
    printf("Current Ticket Number Is:: %d\n",t.tno);
    t.tno++;
    lseek(fd,0,SEEK_SET);//what will now be written will be written in the start
    write(fd,&t,sizeof(t));

    read(fd,&t,sizeof(t));
    printf("Updated Ticket Number Is:: %d\n",t.tno);

    printf("Press Enter To release the lock.\n");
    getchar();
    lock.l_type = F_UNLCK;
    ret = fcntl(fd, F_SETLKW, &lock);
    printf("Lock has been released::\n");
    close(fd);
}