
/* Search function that returns a struct if it matches a key value pair? What if there is more than one?  */
// "Find total price paid at X place"
// "Find all transactions greater than > 100"
// "Find all transcation placed during this time"   
// let's do the first one
// I guess I do not know to link two different c files:w

#include "main.h"

float priceTrans(char * trans)
{
	float price = 0;
	struct transcation *current = thead;
	while (current){
		if (!strcmp(trans, current->name))
			price += current->price;
		current=current->next;
	}
	return price;
}

//so how to do multiple entries; i could just print it out

