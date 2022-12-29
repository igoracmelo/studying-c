#include "llist.h"

llist *llist_find(llist *root, char *value) {
  if (root == NULL)
    return NULL;

  if (strcmp(root->value, value) != 0)
    return llist_find(root->next, value);

  return root;
}

void llist_append(llist *root, char *value) {
  if (root->next) {
    llist_append(root->next, value);
  }

  *(root->next) = (llist){.next = NULL, .value = value};
}
