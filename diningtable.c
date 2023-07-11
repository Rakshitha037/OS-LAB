#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define NUM_PHILOSOPHERS 5
#define NUM_CHOPSTICKS 5
void dine(int n);
pthread_t philosopher[NUM_PHILOSOPHERS];
pthread_mutex_t;
chopstick[NUM_CHOPSTICKS];
int main()
{
    //define counter var i and status_message
    int i,status_message;
    void *msg;
    //Initiaize the semaphore array
    for(i=1;i<=NUM_CHOPSTICKS;i++)
    {
        status_message=pthread_mutex_init(&chopstick[i],NULL);
        //check if the mutex is initialised successfully
if(status_message==-1)
{
    printf("\n Mutex initialisation failed:");
    exit(1);
}
    }
    //run the philosopher threads using *dine() function
    for(i=1;i<=NUM_PHILOSOPHERS;i++)
    {
        status_message=pthread_create(&philosopher[i],NULL,(void*)dine,(int*)i);
        if(status_message!=0)
        {
            printf("\n Thread creation error\n");
            exit(1);
        }
    }
    //wait for all philosophers threads to complete executing(finish dining)before closing the program
for(i=1;i<=NUM_PHILOSOPHERS;i++)
{
    status_message=pthread_join(philosopher[i],&msg);
    if(status_message!=0)
    {
        printf("\n Thread join failed\n");
        exit(1);
    }
}
//destroy the chopstick mutex array
for(i=1;i<=NUM_CHOPSTICKS;i++)
{
    status_message=pthread_mutex_destroy(&chopstick[i]);;
    if(status_message!=0)
    {
        printf("\n Mutex destroyed\n");
        exit(1);
    }
}
return 0;
}
void dine(int n)
{
    printf("\n Philosopoher %d is thinking",n);
    //Philosopher picks up the left chopstick(wait)
    pthread_mutex_lock(&chopstick[n]);
    //Philosopher picks up tHe right chopstick(wait)
    pthread_mutex_lock(&chopstick[(n+1)%NUM_CHOPSTICKS]);
//AFTER PICKING UP BOTH CHOPSTICK PHILOSOPHER STARTS EATING
printf("\n Philosopher %d is eating",n);
sleep(3);
//philosopher places down left chopstick(signal)
pthread_mutex_unlock(&chopstick[n]);
//Philosopher places down the right chopstick (signal)
pthread_mutex_unlock(&chopstick[(n+1)%NUM_PHILOSOPHERS]);
//philosopher finishes eating
printf("\n Philosopher%d finished eating",n);
}
