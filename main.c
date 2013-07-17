/* c1ca by James Baril */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"


int main (int argc, char *argv[])
{
//	printf("%s\n", argv[1]);
	int debug =0;
	if (argc > 1)
		if (!strcmp("-d", argv[1])) debug = 1;
	//char str[1];
	//gets(str)
	//if str == '
	float currentprice;
	char current_t[80];
	FILE *fr;
	fr = fopen("testfile.csv", "r");
	char line[200];
	char *line2;
	fgets(line, 200, fr);
	while(fgets(line, 200, fr) != NULL){ 
		int i =0;
		int type=0;
		line2 = strtok(line, ",\"");
		i++;
		while (line2 !=NULL){
			if (i==3) strncpy(current_t, line2, sizeof(current_t));
			if (i==4||i==5) currentprice = atof(line2);
			if(debug)
				printf("%d:%s\n", i, line2);
			if (i<3)
				line2 = strtok(NULL, "\",");
			else {
				line2 = strtok(NULL, "\n");
				if(line2){
					if (line2[2] == '"'){
						i++;
						if (i==5) type = 1;
					}
				line2 = strtok(line2, ",\"\n");
				}
			}
			i++;
		}
		if (debug)
			printf("adding transcation:%s with price %.2f t=%d\n", current_t, currentprice, type);

		add_trans(current_t, currentprice, type);
	}

	// Linked List version
	/* Test transcations
	add_trans("T1", 55.5);
	add_trans("T2", 45.5);
	add_trans("T3", 65.5);
	*/
	traverse_list();
	printf("Total Purchases: %f\n", get_sum());
	printf("Max Purchase: %f at %s\n", get_max_t()->price, get_max_t()->name);
	//this is bugged still
	//printf("T2 total: %f\n", priceTrans("T2"));
	printf("MARQUIS CINEMA 10 CRESTVIEW FL total: %f\n", priceTrans("MARQUIS CINEMA 10 CRESTVIEW FL"));
	return 0;
}

/* This function iterates through the array of structures to get the sum*/
float get_sum()
{
	struct transaction *current = thead;	
	float sum = 0.0;
	while (current) {
		if (current->type)
			sum += current->price;
		current = current->next;
	}
	return sum	;
}

/*This function returns the maximum transaction*/
struct  transaction * get_max_t ()
{
	struct transaction *current = thead;	
	struct transaction *max_t = thead;
	while (current) {
		if (current->price > max_t->price && current->type )
			max_t = current;
		current = current->next;
	}
	return max_t;
}

/* Traverses the linked list and prints out the name and 
price of each transaction*/
void traverse_list ()
{
	struct transaction *current = thead;	
	
	while (current) {
		if (current->type)
			printf("Purchase: ");
		else
			printf("Payment: ");
//		printf(": %s",)
		printf("%s Price: %.2f \n", current->name, current->price);
		current=current->next;
	}
}

/*Adds a transaction to the end of the linked list*/

int add_trans(char * name, float price, int type)
{
	struct transaction * new_t = malloc(sizeof(struct transaction));
	if (!new_t) return 0;
	strcpy(new_t->name, name);
	new_t->price = price;
	new_t->type = type;
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




