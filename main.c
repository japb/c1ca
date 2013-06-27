/* c1ca by James Baril */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"


int main (int argc, char *argv[])
{
	// Linked List version
		add_trans("BK", 55.5);
		add_trans("Wal", 45.5);
		add_trans("McD", 35.5);
	
	traverse_list();
	return 0;
}

/* This function iterates through the array of structures to get the sum*/
float get_sum()
{
	struct transaction *current = thead;	
	float sum = 0.0;
	while (current) {
		sum += current->price;
		current = current->next;
	}
	return sum	;
}

/*This function returns the maximum transaction*/
struct  transaction * get_max_t ()
{
	//int i;
	struct transaction *current = thead;	
	struct transaction *max_t = thead;
	while (current) {
		if (current->price > max_t->price)
			max_t = current;
		current = current->next;
	}
	return max_t;
}

void traverse_list ()
{
	struct transaction *current = thead;	
	while (current) {
		printf("Transaction: %s, Price: %.2f\n", current->name, current->price);
		current=current->next;
	}
}

int add_trans(char * name, float price)
{
	struct transaction * new_t = malloc(sizeof(struct transaction));
	if (!new_t) return 0;
	strcpy(new_t->name, name);
	new_t->price = price;
	new_t->next = NULL;
	if (!thead) {
		thead = new_t;
		ttail = new_t;
		return 1;
	}
	else{
		ttail->next = new_t;
		ttail = new_t;
		return 1;
	}
}


