/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:09:46 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:44:31 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	remaininglenght;

	i = 0;
	if (little[i] == '\0' || (big == NULL && len == 0))
		return ((char *)big);
	while (big[i] != '\0' && len > 0)
	{
		remaininglenght = len;
		j = 0;
		while (len > 0 && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0' && len > 0)
				return ((char *)(big + i));
			j++;
			len--;
		}
		len = remaininglenght;
		i++;
		len--;
	}
	return (NULL);
}

/*
 *char *
		strnstr(const char *big, const char *little, size_t len);

DESCRIPTION
		The strnstr() function locates the first occurrence of the
		null-terminated string little in the string big,
			where not more than len characters are searched.
			Characters that appear after a ‘\0’ char‐
		acter are not searched.  Since the strnstr() function is a
		FreeBSD specific API,
			it should only be used when portability is not a concern.

RETURN VALUES
		If little is an empty string,
			big is returned; if little occurs nowhere in big,
			NULL is returned; otherwise a pointer to the first character of
			the first occurrence of little is returned. An other possibility
			here is to compare len to i and i
			+ j instead of decreasinf len and using tempon.
		*/
