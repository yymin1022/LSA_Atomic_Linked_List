#include "linked_list_impl.h"

DEFINE_SPINLOCK(ll_lock);
LIST_HEAD(global_list);

void	*add_to_list(int thread_id, int *range_bound)
{
	int		i;
	list_item	*tmp_elem;

	spin_lock(&ll_lock);
	for(i = range_bound[0]; i <= range_bound[1]; i++)
	{
		tmp_elem = kmalloc(sizeof(list_item), GFP_KERNEL);
		tmp_elem->value = i;
		list_add_tail(&tmp_elem->list, &global_list);
	}
	printk("Thread #%d Insert Range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	spin_unlock(&ll_lock);
	return &global_list;
}

void	*search_list(int thread_id, void *data, int *range_bound)
{
	struct list_head	*cur;
	struct list_head	*tmp;

	spin_lock(&ll_lock);
	list_for_each_safe(cur, tmp, &global_list);
	printk("Thread #%d Search Range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	spin_unlock(&ll_lock);
	return cur;
}

void	*del_from_list(int thread_id, int *range_bound)
{
	struct list_head	*cur;
	struct list_head	*tmp;
	list_item		*elem;

	spin_lock(&ll_lock);
	list_for_each_safe(cur, tmp, &global_list)
	{
		elem = list_entry(cur, list_item, list);
		list_del(cur);
	}
	printk("Thread #%d Delete Range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	spin_unlock(&ll_lock);
	return cur;
}
