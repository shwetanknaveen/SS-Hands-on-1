#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sched.h>
int main()
{
	printf("Minimum Priority for FIFO Policy::        %d\n",sched_get_priority_min(SCHED_FIFO));
	printf("Maximum Priority for FIFO Policy::        %d\n",sched_get_priority_max(SCHED_FIFO));
	printf("Minimum Priority for ROUND ROBIN Policy:: %d\n",sched_get_priority_min(SCHED_RR));
	printf("Maximum Priority for ROUND ROBIN Policy:: %d\n",sched_get_priority_max(SCHED_RR));
}