#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main() 
{
    int fd = open("file17", O_CREAT|O_RDWR,0744);//this is the first program hence we  need to set O_CREAT flag so that if 
                                                //file doesn't exist then it should be created
    if(fd == -1) 
    {
      printf("Unable to open the file\n");
      exit(1);
    }
    struct ticket
    {
    	int tno;
    } t;
    int tic;
    printf("Enter a Ticket:: ");
    scanf("%d",&tic);
    t.tno=tic;
    write(fd,&t,sizeof(t));
    read(fd,&t,sizeof(t));
    printf("Ticket Number Saved Is:: %d\n",t.tno);
    close(fd);
}