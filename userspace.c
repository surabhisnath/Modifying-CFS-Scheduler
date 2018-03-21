#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <string.h>

int main()
{
   

    //struct timeval start;
    //gettimeofday(&start,NULL);
    long int pid=fork();
   
   
    if(pid!=0)
    {
        printf("Process 1 %ld\n",getpid());
        printf("Process 2 %ld\n",pid);

        int ret=syscall(323,pid,200);
        
        printf("Process 1 rt_nice = 0\n");
        printf("Process 2 rt_nice = 200\n");
       
    }

   
    if(pid==0)
    {

        long prod=1;
        long i=1;
        for(i=1;i<2000000000;i++)
        {
            prod=prod*i;     
        }

        printf("Process with PID %ld terminated \n",getpid());
       
    }


    else
    {
        long prod=1;
        long i=1;
        for(i=1;i<1000000000;i++)
        {
            prod = prod * i;    
        }

        printf("Process with PID %ld terminated \n",getpid());
        wait(pid);
    }

    return 0;
}