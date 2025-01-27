/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:05:58 by anastruc          #+#    #+#             */
/*   Updated: 2024/04/26 17:44:31 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_substrlen(char const *s, unsigned int start, size_t len)
{
	size_t	substrlen;

	substrlen = 0;
	if (!s)
		return (0);
	while (s[start] && substrlen < len)
	{
		substrlen++;
		start++;
	}
	return (substrlen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned long	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (NULL);
	}
	else
	{
		substr = (char *)malloc(sizeof(char) * (ft_substrlen(s, start, len))
				+ 1);
		if (!substr)
			return (NULL);
		i = 0;
		while (s[start] != '\0' && i < len)
		{
			substr[i++] = s[start++];
		}
		substr[i] = '\0';
	}
	return (substr);
}
/* TO BE IMPROVED
The substr fonction handle two special cases in order to be more secure :
The first one is handled by the if else strucuture in the fonction.
 If s doesn't exist --> Calloc a memory zone of 1 byte.
Calloc = malloc with bzero in it
The second special case is handle by the substrlen subfonction.
 In the case if the len of the asked substr in the fonction
  is greater than the principal str.
To avoid any access to unauthorized memory zone.
 Substrlen cannot be greater than ask len, but moreover cannot be greter
than the len of str
*/
