#include <assert.h>
#include "hashmap.h"

int main()
{
  map m;

  assert(map_get(m, "none") == NULL);

  map_put(m, "name", "Zezinho");
  assert(strcmp(map_get(m, "name"), "Zezinho") == 0);
}
