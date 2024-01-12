#include <stdio.h>
#include "list.h"

int main()
{
	list head = NULL;

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
