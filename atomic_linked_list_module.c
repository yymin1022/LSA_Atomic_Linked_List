#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int	__init atomic_ll_init(void)
{
	printk ("Atomic Linked List 20194094 Yongmin Yoo\n");
	return (0);
}

void	__exit atomic_ll_cleanup(void)
{
	printk ("simple module removed\n");
}

module_init(atomic_ll_init);
module_exit(atomic_ll_cleanup);
MODULE_LICENSE("GPL");
