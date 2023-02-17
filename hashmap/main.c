#include <assert.h>
#include <stdio.h>
#include "hashmap.h"

int main()
{
  map m;
  map_init(m);

  assert(map_get(m, "none") == NULL);
  printf("none is empty\n");

  map_put(m, "name", "Zezinho");
  // printf("put name Zezinho\n");

  // assert(strcmp(map_get(m, "name"), "Zezinho") == 0);
  // printf("name equals Zezinho\n");
}
