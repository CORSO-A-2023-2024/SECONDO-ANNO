#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	list head = NULL, l2 = NULL;

	/* Inserisci alcuni valori a caso */
	head = list_insert_tail(head,15);
	head = list_insert_head(head, 10);
	head = list_insert_head(head, 2);
	head = list_insert_tail(head,17);
	head = list_insert_tail(head, 50);
	list_print(head);
	head = list_delete_if(head, 15);
	list_print(head);
	head = list_delete_odd(head);
	list_print(head);
	head = list_delete_cut_below(head, 5);
	list_print(head);
	list dup = list_dup(head);
	printf("Dup:\n");
	list_print(dup);
	

	return 0;
}


