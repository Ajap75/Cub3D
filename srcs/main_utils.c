/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:16:17 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 13:35:51 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/functions.h"
#include "../headers/structures.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	correct_extension(char *file_name)
{
	if (ft_strlen(file_name) < 5)
		return(1);
	if (file_name[ft_strlen(file_name) - 1] != 'b')
		return (1);
	if (file_name[ft_strlen(file_name) - 2] != 'u')
		return (1);
	if (file_name[ft_strlen(file_name) - 3] != 'c')
		return (1);
	if (file_name[ft_strlen(file_name) - 4] != '.')
		return (1);
	return (0);
}

int	print_map(t_data *data)
{
	int	i;

	i = 0;
	printf("_____________________________________\n__________________MAP_________________\n");
	while (i < data->map.height)
	{
		printf("line [%d] = |%s|\n", i, data->map.layout[i]);
		i++;
	}
	return (0);
}
