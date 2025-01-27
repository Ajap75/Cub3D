/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:10 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:45:02 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*rtn;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (is_in_set(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		rtn = ft_strdup("");
		if (!rtn)
			return (NULL);
		else
			return (rtn);
	}
	while (is_in_set(s1[end - 1], set) == 0)
		end--;
	rtn = ft_substr(s1, start, (end - start));
	return (rtn);
}

/* The firs fonction is_in_set will check if the character is in the string
set going through the entire string set thanks to the loop. As soon as an
ccurence is found the function will return (0), Otherwise, if we reach the null
byte of set (while (*set)), it ends the loop and return (1).

The second fonction :
1) check if s1 is Null (if s1 is null) there waz an memory allocation problem
and the fonction malloc return a pointer to Null, or the string s1 is empty.i

2) check if set is Null. If it's null it means we have nothing to remove
from s1, we can return a copy of s1 using strdup(s1).

3) This part aim to find the begining of the substring to keep. We want to know
at which index start is. We go through the string s1 and checking if the
fonction is_in_set return 0. While it's the case, it's means that every
character of s1 has been found in set. We will iterate on the first characters
of S1 until a character from s1 is not in set.

4)If all character of s1 are in set, return a empty string. Here it,s
a bit special. We will verify if the condition of the second if is true.
We want to know if the allocation of an empty string using strdup has worked and
 does not return NUll. It's a logical negation. so the function return NULL
  if the allocatin has failed. And return rtn if not.

5)Find the end of the substring. Same logic as finding the biginning of
the substring. Be carrefull with the -1 to start at the last character
of the string and not on the null byte, due to the position and size effect.

6)Create the substring from s1 by remooving the characters from set.
*/
