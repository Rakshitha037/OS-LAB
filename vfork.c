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
    }
    else if(pid==0)
    {
        printf("Child process:Hello Iam the child:\n");
        printf("The child process:My pid is %d\n",getpid());
        printf("Child process:My parent pid is %d\n",getppid());
        _exit(0);
    }
    else{
        printf("Parent process:Hello Iam the parent\n");
        printf("Parent proces:my pid is %d]n",getpid());
        printf("Parent process:my child's pid is %d\n",pid);
        int status;
        waitpid(pid,&status,0);
        if(WIFEXITED(status)){
            printf("Parent process:Child process terminated normally\n");
        }
        else{
            printf("Parent process terminate abnormally");
        }

    }
    return 0;
}