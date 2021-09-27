#include<stdio.h> 
#include<sys/types.h> 
#include<unistd.h> 

int main(int argc, char **argv) 
{
	//printf("%d\n",argc);
	//printf("%s\n", argv[2]);
	if(argc>1)
	{
		execl(argv[1],argv[2],argv[3],(char *)NULL);
	}
	else
	{
		printf("Not Enough Arguments To main().\n");
	}
}

//Compile as run the code as following for having long listing of current directory i.e,. directory where .out file is
/*
gcc 26b.c -o 26bout.out
./26bout.out /bin/ls ls -al
*/
