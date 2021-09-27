#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    if(!fork()){//Writing logic for the child
        setsid();//making it independent of session. There is no control terminal in this process. If the process has a control terminal before calling setsid, the contact with the terminal is released . If the process is the leader of a process group, this function returns an error.
        chdir("/");//changing it to root directory
        umask(0);//Setting the umask to 0000 (or just 0 ) means that newly created files or directories created will have no privileges initially revoked. In other words, a umask of zero will cause all files to be created as 0666 or world-writable
            while(1){
                sleep(10);//let parent process die and make this process still running
                printf("Child pid: %d\n",getpid());
                printf("This is my daemon process\n");
            }
    }
    else{//For parent where fork() returns the pid of child created
        exit(0); //Intentionally letting the parent process die while child process is still there
    }
}