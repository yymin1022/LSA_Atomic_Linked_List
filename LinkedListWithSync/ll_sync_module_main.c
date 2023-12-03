#include "linked_list_impl.h"

MODULE_LICENSE("GPL");

struct task_struct **threads;

int	range_bound[4][2] = {
	{0, 249999},
	{250000, 499999},
	{500000, 749999},
	{750000, 999999}
};

static int	list_iter(void *arg)
{
	int	tid;
	int	*iter_range;
	void	*list_head;

	tid = *(int *)arg;
	iter_range = range_bound[tid];
	list_head = add_to_list(tid, iter_range);
	search_list (tid, list_head, iter_range);
	del_from_list (tid, iter_range);
	while(!kthread_should_stop())
		msleep(100);
	printk ("Thread #%d Stopped!\n", tid);
	return (0);
}

int		__init ll_sync_init(void)
{
	int	i;
	int	*arg;

	printk ("LL with Sync Start: 20194094 Yongmin Yoo\n");
	threads = (struct task_struct **)kmalloc(sizeof(struct task_struct *) * 4, GFP_KERNEL);
	for (i = 0; i < 4; i++)
	{
		arg = (int *)kmalloc(sizeof(int), GFP_KERNEL);
		*arg = i;
		threads[i] = kthread_run (&list_iter, (void *)arg, "Linked List");
	}
	return (0);
}

void		__exit ll_sync_cleanup(void)
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
	printk ("Linked List with Sync Module Removed\n");
}

module_init(ll_sync_init);
module_exit(ll_sync_cleanup);
