#include <linux/delay.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

struct task_struct **threads;
int counter;
volatile int test_lock;

static int	atomic_add_func(void *arg)
{
	int	num;

	while (!kthread_should_stop())
	{
		while (__sync_lock_test_and_set(&test_lock, 1));
		num = __sync_lock_test_and_set(&counter, counter + 1);		
		__sync_lock_test_and_set(&test_lock, 0);
		printk("PID[%u] %s: counter is %d\n", current->pid, __func__, num);
		msleep(500);
	}
	return (0);
}

int		__init atomic_practice_init(void)
{
	int	i;

	printk ("Atomic with test_and_set Start: 20194094 Yongmin Yoo\n");
	threads = (struct task_struct **)kmalloc(sizeof(struct task_struct *) * 4, GFP_KERNEL);
	for (i = 0; i < 4; i++)
	{
		threads[i] = kthread_run (&atomic_add_func, NULL, "Atomic Add");
	}
	return (0);
}

void		__exit atomic_practice_cleanup(void)
{
	int	i;

	for(i = 0; i < 4; i++)
	{
		if (threads[i])
		{
			kthread_stop(threads[i]);
			threads[i] = NULL;
			kfree(threads[i]);
		}
	}
	kfree(threads);
	printk ("Atomin with test_and_set Exit: Module Removed\n");
}

module_init(atomic_practice_init);
module_exit(atomic_practice_cleanup);
