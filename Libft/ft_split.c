/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:32:08 by anastruc          #+#    #+#             */
/*   Updated: 2024/05/06 17:32:58 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

static char	*ft_fulfilltab(const char *s, int start, int end, char **dest)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * ((end - start) + 1));
	if (!tab)
		return (ft_free(dest));
	while (start < end)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**dest;
	int		start;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!dest)
		return (NULL);
	j = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			dest[j++] = ft_fulfilltab(s, start, i, dest);
		}
		i++;
	}
	dest[j] = NULL;
	return (dest);
}

/*
int	main(void)
{
	char	s[] = "     kutut dsdds   ksdsd ksdsd dsdds    s s s   ";
	char	c;

	c = ' ';
	printf("il y a %d mots dans cette phrase", ft_countword(s, c));
	return (0);
}

int	main(void)
{
	int		i;
	char	sep;
	char	**dest;
	char	s[] = "  bonjour comment ca va";

	sep = ' ';
	i = 0;
	dest = ft_split(s, sep);
	while (dest[i])
	{
		printf("\n %s \n", dest[i]);
		i++;
	}
	return (0);
}
*/

/*In fulfiltb, pointer to dest is used as a parameter in order to be able
 to free all the subdest in dest if there is a probleme with a malloc of
 a subdest in fullfiltab (cf free function)


Inthe fonction ft_split, the condition of the
loop is while (i < ft_strlen(s))
instead of str[i] because as we increment one
more time i when we goout of the other
loop in the if condition, we go further the null bytes.
If not we will encounter some trouble to place the NULL at the end of the
array of array.
j will be exceeded*/
