/* c1ca by James Baril */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"


int main (int argc, char *argv[])
{

	FILE *fr;
	fr = fopen("testfile.csv", "r");
	char line[200];
	char *line2;
	while(fgets(line, 200, fr) != NULL){ 
		int i =0;
		line2 = strtok(line, ",\"");
		i++;
		//printf("%s", line);
		while (line2 !=NULL){
			printf("%d:%s\n", i, line2);
			if (i<3)
				line2 = strtok(NULL, "\",");
			else{
				char *line3;
				line3 = line2;
				//printf("line3: %s", line3);
				line2 = strtok(NULL, ",");
				if(line2 && !strcmp(line2, "\"\"")){
					//printf("found a \"");
					i++;
					line2 = line3; //go back
					line2 = strtok(NULL, ",\"");
					//line2 = line3; //go back again
				}
				else if(line2){
					line2=line3;
					printf("line: %s", line2);
					line2 = strtok(NULL, ",\"");
					printf("line2b: %s", line2);
				}
				//else if(line2){
					//line2 = line3;	
					//line2 = strtok(NULL, "\",");
				//else
					//line2 = strtok(NULL, "\",");
					//printf("line2a: %s", line2);
					//line2 = line3;
				//}	
			}
			i++;
		}
		//sscanf (line, "%s", line2);

	}
	

	// Linked List version
	add_trans("T1", 55.5);
	add_trans("T2", 45.5);
	add_trans("T3", 65.5);
	traverse_list();
	printf("sum: %f\n", get_sum());
	printf("max: %f\n", get_max_t()->price);
	printf("T2 total: %f\n", priceTrans("T2"));
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
	struct transaction *current = thead;	
	struct transaction *max_t = thead;
	while (current) {
		if (current->price > max_t->price)
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
		printf("Transaction: %s, Price: %.2f\n", current->name, current->price);
		current=current->next;
	}
}

/*Adds a transaction to the end of the linked list*/

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




