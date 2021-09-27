#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

    struct ticket
    {
        int tno;
        char name[20];
    } tdata;

int main() 
{
    int fd = open("ticketdatabase", O_CREAT|O_RDWR,0744);
    if(fd == -1) 
    {
      printf("Unable to open the file\n");
      exit(1);
    }
    for(int i=1;i<=3;i++)
    {
        int tic;
        char *nm;
        printf("Enter a Ticket Number:: ");
        scanf("%d",&tic);
        printf("Enter a Passenger Name:: ");
        scanf("%s", nm);//doesn't allow spaces
        tdata.tno = tic;
        //tdata.name = (char*)malloc(20);  // you can skip memory allocation if you are using array.
        strcpy(tdata.name,nm);  // use copy instead of assignment, that doesnt work with pointer or array .
        write(fd,&tdata,sizeof(tdata));//second parameter is the buffer and third parameter tell that how much data has to
                                        //be written
    }
    close(fd);

    fd = open("ticketdatabase", O_CREAT|O_RDWR,0744);
    if(fd == -1) 
    {
      printf("Unable to open the file\n");
      exit(1);
    }
    for(int i=1;i<=3;i++)
    {
        read(fd,&tdata,sizeof(tdata));//once data size = third parameter has been read then read() advances the pointer
        printf("\nTicket Number:: %d",tdata.tno);
        printf("\tTicket Name:: %s\n",tdata.name);
    }
    close(fd);
}