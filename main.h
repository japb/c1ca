struct transaction {
  float price;
  char name[10];
  struct transaction *next;
} ;
	
float get_sum(struct transaction *t, int);
struct transaction get_max_t (struct transaction *, int);
void traverse_list(struct transaction *);
int add_trans(struct transaction *, char *, float);
