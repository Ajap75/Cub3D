/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:11:17 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/31 14:12:18 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	ft_free_exit(char *line, char	**rgb_tab, t_data *data, int i)
{
	free(line);
	free_char_tab(rgb_tab);
	if (i == 1)
		printf("\033[31mError\n!RGB! Each color must be made of of exactly 3 \
numbers serpareted by a coma\n\033[0m");
	else
		printf("\033[31mError\nDIGIT ONLY : Each color must be made of exactly 3 \
numbers serpareted by a coma\n\033[0m");
	return(ft_clean_data_and_exit(data));
}

int	free_char_tab(char **texture_file)
{
	int	i;

	i = 0;
	if (!texture_file)
		return (0);
	while (texture_file[i])
	{
		free(texture_file[i]);
		i++;
	}
	free(texture_file);
	return (1);
}
