#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    int status;
    pid=fork();
    if(pid<0)
    {
        printf("Error:fork() failed\n");
        return 1;
    }
    else if(pid==0)
    {
        printf("This is the child process with pid:%d\n",getpid());
        printf("The parent process pid:%d\n",getppid());
        execlp("/bin/ls","ls",NULL);
        printf("This should not be printed if exec() is successful\n");
        return 0;
    }
    else{
        printf("This is the parent process with pid: %d\n",getpid());
        printf("The child process pid :%d\n",pid);
        wait(&status);
        printf("The child process exited with status :%d\n",status);
        return 0;
    }
}