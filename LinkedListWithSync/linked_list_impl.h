#ifndef LINKED_LIST_SYNC
# define LINKED_LIST_SYNC
# include <linux/list.h>
# include <linux/module.h>
# include "calclock.h"

void	*add_to_list(int thread_id, int *range_bound);
void	*search_list(int thread_id, void *data, int *range_bound);
void	*del_from_list(int thread_id, int *range_bound);

#endif
