#include "libft.h"

char	*ft_strcat_malloc(char *s1, char *s2)
{
  char	*new_str;
  int		i;
  int		j;

  if (!s1 || !s2)
    return (NULL);
  new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
  if (!new_str)
    return (NULL);
  i = 0;
  while (s1[i])
  {
    new_str[i] = s1[i];
    i++;
  }
  j = 0;
  while (s2[j])
  {
    new_str[i + j] = s2[j];
    j++;
  }
  new_str[i + j] = '\0';
  return (new_str);
}