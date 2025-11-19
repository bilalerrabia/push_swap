#include "push_swap.h"

static size_t	words_count(const char *s, char c)
{
	size_t	res;
	size_t	i;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			res++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (res);
}

static char	**return_empty(void)
{
	char	**res;

	res = malloc(sizeof(char *));
	if (!res)
		return (NULL);
	res[0] = NULL;
	return (res);
}

static char	*get_word(const char *s, size_t *i, char c)
{
	size_t	j;
	size_t	k;
	char	*res;

	j = *i;
	k = 0;
	while (s[j] && s[j] != c)
		j++;
	res = malloc((j - *i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (*i < j)
	{
		res[k] = s[*i];
		(*i)++;
		k++;
	}
	res[k] = '\0';
	return (res);
}

char	**free_all(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(res[i++]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	j;
	char	**res;

	if (!s)
		return (return_empty());
	words = words_count(s, c);
	res = malloc((words + 1) * (sizeof(char *)));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			res[j++] = get_word(s, &i, c);
		if (j > 0 && !res[j - 1])
			return (free_all(res, j));
	}
	res[j] = NULL;
	return (res);
}
