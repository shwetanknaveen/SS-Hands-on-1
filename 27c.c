#include<stdio.h> 
#include<unistd.h> 
int main(int argc, char **argv) 
{
	execle("/bin/ls","ls","-Rl",(char *)NULL,(char *)NULL);
    //ls -Rl should give long reading list of files including those too which in sub directories
}