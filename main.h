struct transaction {
  float price;
  char name[10];
  struct transaction *next;
} *thead, *ttail;
	
float get_sum();
struct  transaction *get_max_t();
void traverse_list();
int add_trans(char *, float);
