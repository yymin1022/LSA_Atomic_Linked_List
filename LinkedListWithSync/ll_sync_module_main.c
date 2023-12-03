#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#include "ll_sync.h"

MODULE_LICENSE("GPL");

int	range_bound[4][2] = {
	{0, 249999},
	{250000, 499999},
	{500000, 749999},
	{750000, 999999}
};

int	__init atomic_ll_init(void)
{
	printk ("Linked List with Sync 20194094 Yongmin Yoo\n");
	return (0);
}

void	__exit atomic_ll_cleanup(void)
{
	printk ("Linked List with Sync Module Removed\n");
}

module_init(atomic_ll_init);
module_exit(atomic_ll_cleanup);
