#include <stdlib.h>
#include <string.h>

typedef struct llist {
  struct llist* next;
  char* value;
} llist;

llist* llist_find(llist* root, char* value);

void llist_append(llist* root, char* value);
