/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:32:17 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/28 11:46:37 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
int	main(void)
{
	int	c;

	c = 65;
	printf("Valeur ascii %c donne %d avec tolower et %d avec ft_tolower\n", c,
		tolower(c), ft_tolower(c));
	c = 90;
	printf("Valeur ascii %c donne %d avec tolower et %d avec ft_tolower\n", c,
		tolower(c), ft_tolower(c));
	c = 25;
	printf("Valeur ascii %c donne %d avec tolower et %d avec ft_tolower\n", c,
		tolower(c), ft_tolower(c));
	c = 45;
	printf("Valeur ascii %c donne %d avec tolower et %d avec ft_tolower\n", c,
		tolower(c), ft_tolower(c));
	c = 75;
	printf("Valeur ascii %c donne %d avec tolower et %d avec ft_tolower\n", c,
		tolower(c), ft_tolower(c));
	c = 0;
	printf("Valeur ascii %c donne %d avec tolower et %d avec ft_tolower\n", c,
		tolower(c), ft_tolower(c));
}
*/
