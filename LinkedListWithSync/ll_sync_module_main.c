#include <linux/delay.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kthread.h>

#include "linked_list_impl.h"

MODULE_LICENSE("GPL");

int	range_bound[4][2] = {
	{0, 249999},
	{250000, 499999},
	{500000, 749999},
	{750000, 999999}
};

static int	list_iter(int *tid, int range_idx)
{
	int	*iter_range;
	void	*list_head;

	iter_range = range_bound[range_idx];
	list_head = add_to_list(*tid, iter_range);
	search_list(*tid, list_head, iter_range);
	del_from_list(*tid, iter_range);
	while (!kthread_should_stop())
		msleep(500);
	printk (KERN_INFO "Thread #%d Stopped!\n", *tid);
	return (0);
}

int		__init atomic_ll_init(void)
{
	int	tid;

	tid = 1234;
	list_iter(&tid, 0);
	printk ("Linked List with Sync 20194094 Yongmin Yoo\n");
	return (0);
}

void		__exit atomic_ll_cleanup(void)
{
	printk ("Linked List with Sync Module Removed\n");
}

module_init(atomic_ll_init);
module_exit(atomic_ll_cleanup);
