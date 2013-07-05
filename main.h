#include "search.h"

struct transaction {
  float price;
  char name[80];
  struct transaction *next;
} *thead, *ttail;
	
float get_sum();
struct  transaction *get_max_t();
void traverse_list();
int add_trans(char *, float);
