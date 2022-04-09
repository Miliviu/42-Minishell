#include "../incs/binary_trees_lib.h"

unsigned long long int  btl_string_score(void *str)
{
  int                       i;
  unsigned char             *aux;
  unsigned long long int    result;

  result = 0;
  aux = str;
  i = -1;
  while (aux[++i])
    result = ((unsigned int) aux[i]) + 256 * result;
  return (result);
}
