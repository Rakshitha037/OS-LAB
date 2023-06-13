#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid=vfork();
    if(pid==-1)
    {
        perror("vfork");
        return 1;
    }else if(pid==0)
    {
        printf("Child process:Hello iam the child\n");
        printf("The child process:My PID  is %d\n",getpid());
        printf("Child process:My parent pid is %d\n",getppid());
        _exit(0);
    }
    else{
        printf("parent process:Hello iam the parent\n");
        printf("parent process:my pid is %d\n",getpid());
        printf("parent process:my child's pid is %d\n",pid);
        int status;
        waitpid(pid,&status,0);
        if(WIFEXITED(status)){
            printf("parent process:child process terminated normally\n");
        }
        else{
             printf("parent process:child process terminated abormally\n");
        }
    }
    return 0;


}
