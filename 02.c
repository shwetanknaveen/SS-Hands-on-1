#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{
	
while(1){
		//for 2nd program in Hands on list 1, we are doing nothing, just created an infinite loop
	}
}

//compile this process with following code
//gcc 02.c -o infiniteLoop.out
//run this process using following command in background and it will return the process id
//	./infiniteLoop.out &
// Now go to /proc directory and run following command in the terminal
// ls -al
//we can kill the process with following code
// kill pid
