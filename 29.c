#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>
#include <pthread.h>

int main(void){
	pid_t pid;
	int ret;
	int val;
	struct sched_param param;
	pid = getpid();
	ret = sched_getscheduler(pid);
	if(ret==SCHED_OTHER) printf("Pid: %d Priority: %d Policy: SCHED_OTHER\n",pid,ret);
	
	param.sched_priority=5;
	val = sched_setscheduler(0,SCHED_FIFO,&param);//0 means changing scheduling policy for the current thread
	ret = sched_getscheduler(pid);
	if(val==-1) perror("sched_setscheduler");
	else if(ret==SCHED_FIFO) printf("Pid: %d Priority: %d Policy: SCHED_FIFO\n",pid,param.sched_priority);
	else printf("Policy not changed to SCHED_FIFO\n");
	
	param.sched_priority=10;
	val = sched_setscheduler(0,SCHED_RR,&param);//0 means changing scheduling policy for the current thread
	ret = sched_getscheduler(pid);
	if(val==-1) perror("sched_setscheduler");
	else if(ret==SCHED_RR) printf("Pid: %d Priority: %d Policy: SCHED_RR\n",pid,param.sched_priority);
	else printf("Policy not changed to SCHED_RR\n");
	
	return 0;
}

//To change scheduling schemes and priorities we need to be super user hence run out file of this code as
    //      sudo 29out.out

/*
int sched_setscheduler(pid_t pid, int policy,const struct sched_param *param);

The sched_setscheduler() system call sets both the scheduling
       policy and parameters for the thread whose ID is specified in
       pid.  If pid equals zero (0), the scheduling policy and parameters of
       the calling thread will be set.

       The scheduling parameters are specified in the param argument,
       which is a pointer to a structure of the following form:

           struct sched_param {
               ...
               int sched_priority;
               ...
           };The sched_setscheduler() system call sets both the scheduling
       policy and parameters for the thread whose ID is specified in
       pid.  If pid equals zero, the scheduling policy and parameters of
       the calling thread will be set.

       The scheduling parameters are specified in the param argument,
       which is a pointer to a structure of the following form:

           struct sched_param {
               ...
               int sched_priority;
               ...
           };
*/
