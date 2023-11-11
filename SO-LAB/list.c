#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node * next; 
} node;

typedef node* list;

list list_insert_ordered(list p, int val){
	int found = 0; 
	node * null = NULL;
	node * insert = {val, null};
	list swap;
	while(p != NULL && !found){
		if(p->next->value < val){
			swap = p->next; 
			p->next = insert;
			insert->next = swap;
			found = 1;
		}
		p = p->next;
	}
	return p;
}

list list_cat(list before, list after);
list list_insert_head(list p, int val);
list list_insert_tail(list p, int val);
list list_insert_head(list p, int val)
{
	list new_el;

	/* Allocate the new node */
	new_el = malloc(sizeof(*new_el));
	/* Setting the data */
	new_el->value = val;
	/* head insertion: old head becomes .next field of new head */
	new_el->next = p;
	/* new head is the pointer to the new node */
	return new_el;
}

void list_print(list p)
{
	/* Looping all nodes until p == NULL */
	if (p == NULL) {
		printf("Empty list\n");
		return;
	}
	printf("[%i]", p->value);
	for(; p->next!=NULL; p = p->next) {
		printf(" -> [%i]", p->next->value);
	}
	printf("\n");
}

void list_free(list p)
{
	/* If p ==  NULL, nothing to deallocate */
	if (p == NULL) {
		return;
	}
	/* First deallocate (recursively) the next nodes... */
	list_free(p->next);
	/* ... then deallocate the node itself */
	free(p);
}

int main()
{
	list head = NULL;

	head = list_insert_head(head, 10);
	head = list_insert_head(head, 2);
	head = list_insert_head(head, 15);
	
	list_print(head);
	
	list_free(head);

	return 0;
}
