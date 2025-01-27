/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:32:32 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/21 18:12:15 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char ))
{
	char			*nstr;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!nstr)
		return (NULL);
	nstr[ft_strlen(s)] = '\0';
	i = 0;
	while (s[i])
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	return (nstr);
}

/*  Function Name: ft_strmapi
This is the name of the function you are declaring.
Return Type: char *

This indicates that the function returns a pointer to a character (char *).
Parameters:

char const *s: This is a pointer to a constant character (string).
 It's the input string on which the mapping function will be applied.
char (*f)(unsigned int,
	char): This is a function pointer named f.
	It points to a function that takes two parameters:
unsigned int: An unsigned integer parameter.
char: A character parameter.
The function returns a char.
So, in summary,
	ft_strmapi is a function that takes a string (s) and a function pointer (f).
		It applies the function f to each character in the input string s,
	and the result is a new string (or an array of characters)
		that is returned by the function. */
