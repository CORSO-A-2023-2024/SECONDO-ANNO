#ifndef LIST_H
#define LIST_H

typedef struct node {
	int value;
	struct node * next;   /* Puntatore alla stessa struttura */
} node;

typedef node* list;

list list_insert_ordered(list p, int val);

list list_cat(list before, list after);

list list_insert_head(list p, int val);

list list_insert_tail(list p, int val);

void list_print(list p);

void list_free(list p);

list list_delete_if(list head, int delete_to);

list list_delete_odd(list head);

list list_delete_cut_below(list head, int cut_val);

list list_dup(list head);

#endif
