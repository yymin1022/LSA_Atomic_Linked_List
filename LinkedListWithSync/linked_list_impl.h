#ifndef LINKED_LIST_SYNC
# define LINKED_LIST_SYNC
# include <linux/delay.h>
# include <linux/list.h>
# include <linux/module.h>
# include <linux/slab.h>
# include <linux/spinlock.h>
# include "calclock.h"

typedef struct {
	struct list_head list;
	int value;
}	list_item;

void	*add_to_list(int thread_id, int *range_bound);
void	*search_list(int thread_id, void *data, int *range_bound);
void	*del_from_list(int thread_id, int *range_bound);

#endif
