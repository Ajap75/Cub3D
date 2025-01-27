/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:47:02 by anastruc          #+#    #+#             */
/*   Updated: 2024/05/08 10:55:48 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;

	if (alst)
	{
		if (*alst)
		{
			current = *alst;
			while (current->next)
			{
				current = current->next;
			}
			current->next = new;
		}
		else
		{
			*alst = new;
		}
	}
}

/* This function add a new element at the end of the list.
It takes as parameter a pointer to a pointer to the firstelement of a list,
and a pointer to a new element.
First, it checks if the pointer alst is null. Then it checks if the list
 is empty.
it had previously create a current element to go through the element of the
list without losing the adress of the first element contain in alst.
We create a reference.
Then we go through the list using a loop. The loop will stop if (current->next)
equal to null. Which means we've reached the last element.
Once we're on the last element. We set the pointer next of the last element
to new. And we set the pointer next of new to null as new is now the last
element.
Otherwise if the condition of the existing linked list is not verified, it means
that the list is empty. So the new element will be the first one
new->next = Null  and *alst = new*/
