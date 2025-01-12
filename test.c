#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
  char *s = malloc((size_t)INT_MAX +5);
  for(size_t i = 0; i < (size_t)INT_MAX+4; i++)
  {
    s[i] = 'a';
    printf("%zu\n", i);
  }

  int out = snprintf(NULL, 0, "%s", s);
  printf("%d\n", out);
  return 0;
}
