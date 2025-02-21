/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:16 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 13:36:47 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"


int	parse_map(t_data *data)
{
	data->config.map_file_fd = ft_open_file(data->config.map_filename);
	skip_metadata(data);
	get_map_index(data);
	ft_end_file(data);
	data->config.map_file_fd = ft_open_file(data->config.map_filename);
	ft_go_to_map(data);
	ft_store_map(data);
	replace_spaces(data);
	print_map(data);
	check_allowed_character(data);
	check_player(data);
	print_map(data);
	check_boundaries(data);
	printf("Map height = %d\n", data->map.height);
	floodfill_algo(data, data->map.player_i, data->map.player_j);
	print_map(data);
	check_algo_floodfill(data);
	restore_map(data);
	return (0);
}

int	ft_store_map(t_data *data)
{
	ft_calculate_map_height_and_width(data);
	ft_end_file(data);
	ft_store(data);
	return (0);
}


int hole_in_the_map(t_data *data, int i, int j)
{
	int	len;
	if	(!is_walkable(data->map.layout[i][j]))
		return(0);
	printf("LINE = |%s|\n", data->map.layout[i]);
	if (i == 0 || i == data->map.height - 1 || j == 0 || j == (int)ft_strlen(data->map.layout[i]) - 1)
		return (1);
	len = ft_strlen(data->map.layout[i - 1]);
	if (j >= len)
		return(1);
	len = ft_strlen(data->map.layout[i + 1]);
	if (j >= len)
		return(1);
	return (0);

}




int	floodfill_algo(t_data *data, int i, int j)
{

	if (i < 0 || i >= data->map.height)
		return (0);
	if (j < 0 || j >= (int)ft_strlen(data->map.layout[i]))
		return (0);
	printf("Accessing : P[%d][%d] = %c \n", i ,j, data->map.layout[i][j]);
	if (!data->map.layout[i][j])
		return(0);
	if (data->map.layout[i][j] == '1' || data->map.layout[i][j] == 'P')
		return(0);
	else
		data->map.layout[i][j] = 'P';
	floodfill_algo(data, i - 1, j);
	floodfill_algo(data, i + 1, j);
	floodfill_algo(data, i, j - 1);
	floodfill_algo(data, i, j + 1);
	return(0);
}
int	check_algo_floodfill(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < (int)ft_strlen(data->map.layout[i]))
		{
			if (data->map.layout[i][j] == '1' || data->map.layout[i][j] == 'P')
				j++;
			else
			{
				printf("\033[31mError\nPosition [%d][%d] is unreachable by the player\n\033[0m", i, j);
				ft_clean_data_and_exit(data);
			}
		}
		j = 0;
		i++;
	}
	return (0);
}
