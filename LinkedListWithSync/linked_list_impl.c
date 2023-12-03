#include "linked_list_impl.h"

DEFINE_SPINLOCK(ll_lock);

void	*add_to_list(int thread_id, int *range_bound)
{
	spin_lock(&ll_lock);
	printk("Thread #%d Insert Range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	msleep(100);
	spin_unlock(&ll_lock);
	return NULL;
}

void	*search_list(int thread_id, void *data, int *range_bound)
{
	spin_lock(&ll_lock);
	printk("Thread #%d Search Range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	msleep(100);
	spin_unlock(&ll_lock);
	return NULL;
}

void	*del_from_list(int thread_id, int *range_bound)
{
	spin_lock(&ll_lock);
	printk("Thread #%d Delete Range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	msleep(100);
	spin_unlock(&ll_lock);
	return NULL;
}
