#include "hashmap.h"

uint8_t hash(char *s) {
  uint8_t res = 0;

  while (*s != '\0') {
    res += *s + 19 * res;
    s++;
  }

  return res % HASHSIZE;
}

void map_put(map m, char *key, char *value) {
  uint8_t h = hash(key);
  llist *root = &m[h];
  llist *pos = llist_find(root, key);

  if (pos)
    pos->value = value;
  else
    llist_append(root, value);
}

char *map_get(map m, char *key) {
  uint8_t h = hash(key);
  llist *root = &m[h];
  llist *pos = llist_find(root, key);

  if (!pos)
    return NULL;

  return pos->value;
}
