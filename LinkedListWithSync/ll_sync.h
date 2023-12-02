#ifndef LINKED_LIST_SYNC
# define LINKED_LIST_SYNC
# include <linux/module.h>

# define list_for_each(pos, n, head) \
	for (pos = head->next, n = pos->next; pos != head; \
		pos = n, n = pos->next)
# define list_for_each_prev(pos, n, head) \
	for(pos = head->prev; n = pos->prev; \
		pos != head; pos = n, n = pos->prev)
# define list_entry(ptr, type, member) \
	container_of(ptr, type, memner)
# define list_for_each_entry(pos, n, head, member) \
	for(pos = list_first_entry(head, typeof(*pos), member), \
		n = list_next_entry(pos, member); \
		&pos->member != head; \
		pos = n, n = list_next_entry(n, member))
# define list_for_each_entry_reverse(pos, n, head, member) \
	for(pos = list_last_entry(head, typeof(*pos), member), \
		n = list_prev_entry(pos, member); \
		&pos->member != head; \
		pos = n, n = list_prev_entry(n, member))

void	list_add(struct list_head *new, struct list_head *head);
void	list_add_tail(struct list_head *new, struct list_head *head);
void	list_del(struct list_head *entry);
void	list_move(struct list_head *list, struct list_head *head);
void	list_move_tail(struct list_head *list, struct list_head *head);
void	list_splice(const struct list_head *list, struct list_head *head);
void	test_print(void);

#endif
