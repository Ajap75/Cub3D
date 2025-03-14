/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:09 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 13:37:36 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"


int	restore_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < (int)ft_strlen(data->map.layout[i]))
		{
			if (data->map.layout[i][j] == 'P')
				data->map.layout[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}
	data->map.layout[data->map.player_i][data->map.player_j] = data->map.player_dir;
	return (0);
}

int	check_boundaries(t_data *data)
{
	check_every_neighbore(data);
	check_first_last_row(data);
	check_first_last_column(data);
	return (0);
}



int	check_every_neighbore(t_data *data)
{

	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < (int)ft_strlen(data->map.layout[i]))
		{
			if (hole_in_the_map(data, i ,j))
			{
				printf ("\033[31mError\n  Map has an acces to a hole at Point[%d][%d]\n\033[0m", i, j);
				ft_clean_data_and_exit(data);
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf ("Map isn't jagged\n");
	return (0);
}


int	ft_fill_layout(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	ft_initialize_layout(data);
	while (i < data->map.height)
	{
		line = get_next_line(data->config.map_file_fd);
		line = ft_trim_line(line);
		if (line == NULL)
			return (0);
		if (line[0] == '\0' || line[0] == '\n' || line[0] == '\r')
		{
			free(line);
			return (0);
		}
		data->map.layout[i] = ft_strdup(line);
		// printf("LINE = [%d] = |%s|\n", i, data->map.layout[i]);
		free(line);
		i++;
	}
	return (0);
}

int	is_walkable(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}
