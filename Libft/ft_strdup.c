/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:45:40 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:42:41 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstring;
	int		i;
	int		size;

	size = 0;
	while (s[size])
		size++;
	newstring = malloc((sizeof(char) * (size + 1)));
	if (!newstring)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstring[i] = s[i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

/*  The  strdup()  function returns a pointer to a new string
which is a duplicate of the string s.  Memory for the new string is ob‐
		tained with malloc(3), and can be freed with free(3).

		The strndup() function is similar,
			but copies at most n bytes.  If s is longer than n,
			only n bytes are copied, and a terminating
		null byte ('\0') is added.

		strdupa()  and  strndupa() are similar,
			but use alloca(3) to allocate the buffer.
			  They are available only when using the GNU GCC
		suite, and suffer from the same limitations described in alloca(3).

RETURN VALUE
		On success,
			the strdup() function returns a pointer to the duplicated string.
			  It returns NULL if insufficient memory was  avail‐
		able, with errno set to indicate the cause of the error.
*/
