#include "../incs/btl.h"

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
