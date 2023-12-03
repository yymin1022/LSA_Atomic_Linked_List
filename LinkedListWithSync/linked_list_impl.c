#include "linked_list_impl.h"

DEFINE_SPINLOCK(ll_lock);
LIST_HEAD(global_list);

unsigned long long cnt_add, cnt_search, cnt_del;
unsigned long long time_add, time_search, time_del;

void	*add_to_list(int thread_id, int *range_bound)
{
	int		i;
	list_item	*tmp_elem;
	struct timespec	stopwatch[2];

	spin_lock(&ll_lock);
	for(i = range_bound[0]; i <= range_bound[1]; i++)
	{
		getrawmonotonic(&stopwatch[0]);
		tmp_elem = kmalloc(sizeof(list_item), GFP_KERNEL);
		tmp_elem->value = i;
		list_add_tail(&tmp_elem->list, &global_list);
		getrawmonotonic(&stopwatch[1]);
		calclock(stopwatch, &time_add, &cnt_add);
	}
	printk("Thread #%d Insert Range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	spin_unlock(&ll_lock);
	return &global_list;
}

void	*search_list(int thread_id, void *data, int *range_bound)
{
	struct list_head	*cur;
	struct list_head	*tmp;
	struct timespec		stopwatch[2];

	spin_lock(&ll_lock);
	getrawmonotonic(&stopwatch[0]);
	list_for_each_safe(cur, tmp, &global_list)
	{
		getrawmonotonic(&stopwatch[0]);
		getrawmonotonic(&stopwatch[1]);
		calclock(stopwatch, &time_search, &cnt_search);
	}
	printk("Thread #%d Search Range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	spin_unlock(&ll_lock);
	return cur;
}

void	*del_from_list(int thread_id, int *range_bound)
{
	list_item		*elem;
	struct list_head	*cur;
	struct list_head	*tmp;
	struct timespec		stopwatch[2];

	spin_lock(&ll_lock);
	list_for_each_safe(cur, tmp, &global_list)
	{
		getrawmonotonic(&stopwatch[0]);
		elem = list_entry(cur, list_item, list);
		list_del(cur);
		getrawmonotonic(&stopwatch[1]);
		calclock(stopwatch, &time_del, &cnt_del);
	}
	printk("Thread #%d Delete Range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	spin_unlock(&ll_lock);
	return cur;
}
