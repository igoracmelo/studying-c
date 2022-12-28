#include <stdint.h>

int main ()
{
  // not very portable
  {
    int16_t i16;
    uint32_t u32;
  }

  // portable
  {
    int_least16_t i16;
    uint_least64_t u64;

    // remember: wrapping int is undefined behavior
    // remember: wrapping uint is not guaranteed to happen always in the same value
  }

  return 0;
}
