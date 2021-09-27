#include<stdio.h> 
#include<unistd.h> 
int main(int argc, char **argv) 
{
	char *args[]={"ls","-Rl",(char*)NULL};
	execvp("ls",args);
    //ls -Rl should give long reading list of files including those too which in sub directories
}