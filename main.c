/* c1ca by James Baril */
#include <stdio.h>
#include <string.h>


struct transaction {
	float price;
	char name[10];
} ;


float get_sum(struct transaction *t, int length);
struct transaction get_max_t (struct transaction *t, int length);

int main (int argc, char *argv[])
{
	struct transaction t_list[2];
	struct transaction *t;
	t = &t_list[0];
	t_list[0].price = 15.0;
	strcpy(t_list[0].name, "Walmart");
	t_list[1].price = 10.0;
	strcpy(t_list[1].name, "BK");

	printf("total sum of transactions: %f\n ", get_sum(t, 2));	
	printf("max price: %f\n ", get_max_t(t, 2).price);	

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


