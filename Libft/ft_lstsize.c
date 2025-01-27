/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:17:20 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/24 14:33:57 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (size);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/* This function count the size of the linked chain.
It takes as a parameter a pointer to the first elemt of a linked chain.
First it will check if the first parameter of the chain does exist, which means
that the linked chain itsefl does exist. If yes, it will start a loop.
In the loop, size is incremented and the pointer lst is updated to point to the
next element. The adress contained in the pointer will be updated each time.
This is made possible thanks to the membre next in each element which contained
a pointer to the next element of the linked chain. It contains the adress of
the next element*/
