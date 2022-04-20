#include "../incs/binary_trees_lib.h"

void    btl_print_ull(unsigned long long int n)
{
  unsigned char aux;

  if (n)
  {
    btl_print_ull(n / 10);
    aux = (unsigned char) n % 10 + '0';
    write(1, &aux, 1);
  }
}

int btl_strlen(char *aux)
{
  int   i;

  i = 0;
  while (aux[i])
    i++;
  return (i);
}
