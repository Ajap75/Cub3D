/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:56:38 by anastruc          #+#    #+#             */
/*   Updated: 2023/11/27 09:07:06 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
			new->next = *alst;
		*alst = new;
	}
}

/* This function add a new element to the list through the front of the list
It takes as parameter a pointer to pointer to the first element of the list
First it checks if the pointer is null if (alst) then it checks if the list is
empty if (*alst), then it affects the adress of the actual first element of the
list to the member next of the new new element.
Then it updates the pointer to the first element of the list *alst
---> *alst (pointer to the first element) became new --> *alst = new/*/
