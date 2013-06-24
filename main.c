/* c1ca by James Baril */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct transaction {
	float price;
	char name[10];
	struct transaction *next;
} ;


float get_sum(struct transaction *t, int length);
struct transaction get_max_t (struct transaction *t, int length);
void traverse_list (struct transaction *thead);

int main (int argc, char *argv[])
{
	// Array version
	struct transaction t_list[2];
	struct transaction *t;
	t = &t_list[0];
	t_list[0].price = 15.0;
	strcpy(t_list[0].name, "Walmart");
	t_list[1].price = 10.0;
	strcpy(t_list[1].name, "BK");
	printf("total sum of transactions: %f\n ", get_sum(t, 2));	
	printf("max price: %f\n ", get_max_t(t, 2).price);	

	// Linked List version
	struct transaction *thead;
	struct transaction *temp = malloc(sizeof(struct transaction));
	temp->price=30.0;
	strcpy(temp->name, "T1");
	thead = temp;
	struct transaction *temp2 = malloc(sizeof(struct transaction));
	temp2->price=35.0;
	strcpy(temp->name, "T2");
	temp->next = temp2;
	temp2->next = NULL;
	traverse_list(thead);
	return 0;
}

/* This function iterates through the array of structures to get the sum*/

float get_sum(struct transaction *t, int length)
{
	float sum = 0.0;
	int i;
	for (i = 0; i < length; i++)
		sum += t[i].price;
	return sum	;
}

/*This function returns the maximum transaction*/

struct transaction get_max_t (struct transaction *t, int length)
{
	int i;
	struct transaction max_t = *t;
	for (i =0; i < length; i++)
			if (t[i].price > max_t.price)
				max_t = t[i];

	return max_t;
}

void traverse_list (struct transaction *thead)
{
	struct transaction *current = thead;	
	//printf("Transaction: %f\n", current->price);
	//current=current->next;
	//printf("Transaction: %f\n", current->price);
	 while (current) {
		printf("Transaction: %f\n", current->price);
		current=current->next;
	}

	

}


