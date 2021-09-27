#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct ticket
{
    int tno;
    char name[20];
}tdata;

int main() 
{
	int fd=open("ticketdatabase",O_RDWR);
	int s=0;
	struct flock lock;
	lock.l_start = 0;
 	lock.l_len = sizeof(tdata);
 	lock.l_pid=getpid();
 	while(1)
 	{
 		lock.l_start = s;
 		lock.l_type = F_WRLCK;
    	lock.l_whence = SEEK_SET;
    	lock.l_pid = getpid();

 		fcntl(fd, F_SETLKW, &lock);
 		s=s+sizeof(tdata);

 		int size=read(fd,&tdata,sizeof(tdata));
 		if(size==0)
 		{
 			printf("\n\nNo More Records.\n");
 			break;
 		}
 		printf("\n\nRecord Locked\n");
 		printf("Ticket Name:: %s",tdata.name);
		printf("\tTicket Number:: %d\n",tdata.tno);
		
		char c;
		printf("Do You Want To Modify This Record. (n/y):: ");
		scanf("%c",&c);
		while(c!='y' && c!='n')scanf("%c",&c);
		if(c=='y')
		{
			lseek(fd,-sizeof(tdata),SEEK_CUR);//since this record has to be modified and with read() we are at end of 
                                            //current record hence we need to go back

			int tic;
        	char nm[20];
        	printf("Enter A Ticket Number:: ");
	        scanf("%d",&tic);
	        printf("Enter A Ticket Name:: ");//doesn't allow spaces
	        scanf("%s", nm);
	        
	        tdata.tno = tic;
	        strcpy(tdata.name,nm);

	        int wr=write(fd,&tdata,sizeof(tdata));
	        printf("Record Modified\n\n");
		}
 		lock.l_type = F_UNLCK;
 		fcntl(fd, F_SETLK, &lock);
        printf("\nLock for the above record has been released\n");
 	}
}