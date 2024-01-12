#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list list_insert_head(list p, int val)
{
	list new_el;

	/* Alloca e inizializza il nuovo elemento */
	new_el = malloc(sizeof(*new_el));
	new_el->value = val;
	/* Appendi la vecchia lista in coda al nuovo elemento */
	new_el->next = p; 
	return new_el;
}

void list_print(list p)
{
	if (p == NULL) {
		printf("Empty list\n");
		return;
	}
	for(; p; p = p->next) {
		printf("-> %i ", p->value);
	}
	printf("\n");
}

void list_free(list p)
{
	if (p == NULL) {
		return;
	}
	/* 
	 * Versione ricorsiva: (1) fai list_free dei prossimi
	 * elementi, poi (2) dealloca l'elemento corrente
	 */
	list_free(p->next);
	free(p);
}

/* Versione ricorsiva */
list list_insert_ordered(list p, int val)
{
	if (p == NULL) {
		/* lista vuota: inserisci in testa */
		return list_insert_head(p, val);
	}
	/* Da qui in poi, la lista non e` vuota */
	if (val <= p->value) {
		/* val e` il minimo: inserisci in testa */
		return list_insert_head(p, val);
	}
	/* Dobbiamo passare al prossimo elemento */
	p->next = list_insert_ordered(p->next, val);
	return p;
}

/* Versione iterativa */
list list_cat(list before, list after)
{
	list p_iter;

	if (before == NULL) {
		return after;
	}
	/* Scorri fino a quando p_iter->next e` NULL */
	for (p_iter = before; p_iter->next; p_iter = p_iter->next);

	/* Concatena le due liste */
	p_iter->next = after;
	return before;
}

list list_insert_tail(list p, int val)
{
	if (p == NULL) {
		/* Se p e` NULL, ins. in coda = ins. in testa */
		return list_insert_head(p, val);
	}
	/* Scorri la lista ricorsivamente fino in fondo */
	p->next = list_insert_tail(p->next, val);
	return p;
}

list list_delete_if(list head, int to_delete){
	list dummy = head;
	list prev = NULL;
	
	if(head == NULL){
		return head;
	}
	
	for(; dummy != NULL && dummy->value != to_delete; dummy = dummy->next){
		prev = list_insert_tail(prev, dummy->value);
	}
	prev = list_cat(prev, dummy->next);

	return prev;
}

list list_delete_odd(list head){
	int count = 1;
	list ris = head;
	
	if(head == NULL){
		return head;
	}
	
	for(; head != NULL; head = head->next, count++){
		if(count % 2 != 0){
			ris = list_delete_if(ris, head->value);
		}
	}
	
	return ris;
}

list list_delete_cut_below(list head, int cut_val){
	list ris = head;
	if(head == NULL){
		return head;
	}
	for(; head != NULL; head = head->next){
		if(head->value < cut_val){
			ris = list_delete_if(head, head->value);
		}
	}
	return ris;
}

list list_dup(list head){
	list ris = NULL;
 	
	if(head != NULL){
		for(;head != NULL; head = head->next) ris = list_insert_tail(ris, head->value);
	}
	
	return ris;
}
