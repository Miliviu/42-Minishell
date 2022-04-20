#include "../incs/binary_trees_lib.h"

int btl_strlen(char *aux)
{
  int   i;

  i = 0;
  while (aux[i])
    i++;
  return (i);
}

int	btl_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char)s2[i]);
}
