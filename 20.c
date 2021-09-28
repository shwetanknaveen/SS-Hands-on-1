#include<stdio.h>
#include<unistd.h>
#include <sys/resource.h>
int main(){
	int prio = getpriority(PRIO_PROCESS,0);
    /*The value which is one of PRIO_PROCESS, PRIO_PGRP, or PRIO_USER,
       and who is interpreted relative to which (a process identifier
       for PRIO_PROCESS, process group identifier for PRIO_PGRP, and a
       user ID for PRIO_USER).  A zero value for who denotes
       (respectively) the calling process, the process group of the
       calling process, or the real user ID of the calling process.*/
	printf("Priority of current process = %d\n",prio);
    nice(-20);//use sudo to increase the priority of the process where lower number indicates the higher priority
    printf("Modified  Priority of current process = %d\n",getpriority(PRIO_PROCESS,0));
	return 0;
}
