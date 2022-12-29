#pragma once
#include "llist.h"
#include <stdint.h>

#define HASHSIZE 101

typedef llist map[HASHSIZE];

uint8_t hash(char *s);

void map_put(map m, char *key, char *value);

char *map_get(map m, char *key);
