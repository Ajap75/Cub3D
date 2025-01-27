/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:16:14 by anastruc          #+#    #+#             */
/*   Updated: 2024/05/06 17:16:37 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countword(const char *s, char c)
{
	int	trigger;
	int	i;
	int	count;

	trigger = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (trigger == 1 && s[i] != c)
		{
			count++;
			trigger = 0;
		}
		if (s[i] == c)
			trigger = 1;
		i++;
	}
	return (count);
}
