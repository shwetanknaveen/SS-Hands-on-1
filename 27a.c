#include<stdio.h> 
#include<sys/types.h> 
#include<unistd.h> 

int main(int argc, char **argv) 
{
	execl("/bin/ls","ls","-Rl",(char *)NULL);//executes path
    //ls -Rl should give long reading list of files including those too which in sub directories
}