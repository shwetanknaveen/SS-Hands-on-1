#include<stdio.h> 
#include<sys/types.h> 
#include<unistd.h> 

int main(int argc, char **argv) 
{
	execlp("ls","ls","-Rl",(char *)NULL);//execute file
    //ls -Rl should give long reading list of files including those too which in sub directories
}