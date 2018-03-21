#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include<asm/errno.h>

asmlinkage long sys_rtnice(int PID, long rtnice)
{
	struct sched_entity *sen;
	struct task_struct *process;

	unsigned long long  int rtval = (unsigned long long  int)rtnice*1000000000;


	if(PID<0)
		return ESRCH;

	for_each_process(process)
	{

		sen = &(process->se);
		
		if((long)task_pid_nr(process)==PID)
		{
			sen->rtnice = rtval;
		}

	}

	return 0;
}