#include <linux/delay.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/slab.h>

#include "linked_list_impl.h"

MODULE_LICENSE("GPL");

int	range_bound[4][2] = {
	{0, 2499},
	{2500, 4999},
	{5000, 7499},
	{7500, 9999}
};

static int	list_iter(void *arg)
{
	int	tid;
	int	*iter_range;
	void	*list_head;

	tid = *(int *)arg;
	iter_range = range_bound[tid];
	list_head = add_to_list(tid, iter_range);
	search_list(tid, list_head, iter_range);
	del_from_list(tid, iter_range);
	printk ("Thread #%d Stopped!\n", tid);
	return (0);
}

int		__init atomic_ll_init(void)
{
	int	i;
	int	*arg;

	printk ("LL with Sync Start: 20194094 Yongmin Yoo\n");
	for (i = 0; i < 4; i++)
	{
		arg = (int *)kmalloc(sizeof(int), GFP_KERNEL);
		*arg = i;
		kthread_run (&list_iter, (void *)arg, "Linked List");
	}
	printk ("LL with Sync Exit: 20194094 Yongmin Yoo\n");
	return (0);
}

void		__exit atomic_ll_cleanup(void)
{
	printk ("Linked List with Sync Module Removed\n");
}

module_init(atomic_ll_init);
module_exit(atomic_ll_cleanup);
