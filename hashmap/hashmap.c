#include "hashmap.h"
#include <stdio.h>

uint8_t hash(char* s) 
{
  uint8_t res = 0;
  
  while (*s != '\0')
  {
    res += *s + 19 * res;
    s++;
  }

  return res % HASHSIZE;
}

void map_init(map m)
{
  for (int i = 0; i < HASHSIZE; i++)
  {
    m[i] = (llist) { NULL, NULL };
  }
}

void map_put(map m, char* key, char* value)
{
  uint8_t h = hash(key);
  llist* root = &m[h];
  llist* pos = llist_find(root, key);

  if (pos)
    pos->value = value;
  else if (root)
    llist_append(root, value);
  else
    m[h] = (llist) { NULL, value };
}

char* map_get(map m, char* key)
{
  uint8_t h = hash(key);
  llist* root = &m[h];
  llist* pos = llist_find(root, key);

  if (!pos)
    return NULL;

  return pos->value;
}


