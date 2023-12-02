#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#include "ll_sync.h"

MODULE_LICENSE("GPL");

int	__init atomic_ll_init(void)
{
	printk ("Linked List with Sync 20194094 Yongmin Yoo\n");
	test_print();
	return (0);
}

void	__exit atomic_ll_cleanup(void)
{
	printk ("Linked List with Sync Module Removed\n");
}

module_init(atomic_ll_init);
module_exit(atomic_ll_cleanup);
