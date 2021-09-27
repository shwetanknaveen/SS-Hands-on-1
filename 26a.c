#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h> 
int main() 
{  
	execl("/bin/ls","ls","-al",(char *)NULL);//The "total" on execution of this command is the disk usage of listed files
	return 0; 
} 