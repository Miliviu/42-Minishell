#include "../incs/binary_trees_lib.h"

int  btl_str_distance(void *s1, void *s2)
{
	int		s1_len;
	int		s2_len;
	int		cmp;

	s1_len = btl_strlen(s1);
	s2_len = btl_strlen(s2);
	if (s1_len == s2_len)
	{
		cmp = btl_strncmp(s1, s2, s1_len);
		if (!cmp)
			return (0);
		else if (cmp > 0)
			return (1);
		return (-1);
	}
	else if (s1_len > s2_len)
		return (1);
	return (-1);
}
