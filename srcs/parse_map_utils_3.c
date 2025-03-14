/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:21:48 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 13:34:58 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	check_first_last_row(t_data *data)
{
	int	i;

	i = 0;
	while (i < ((int)ft_strlen(data->map.layout[0])))
	{
		if (data->map.layout[0][i] != '1')
		{
			printf("\033[31mError\nThe Map must be closed (First row : Point[0][%d])\n\033[0m",
				i);
			ft_clean_data_and_exit(data);
		}
		i++;
	}
	i = 0;
	while (i < ((int)ft_strlen(data->map.layout[data->map.height - 1])))
	{
		if (data->map.layout[data->map.height - 1][i] != '1')
		{
			printf("\033[31mError\nThe Map must be closed (Last row : Point[%d][%d])\n\033[0m",
				data->map.height - 1, i);
			ft_clean_data_and_exit(data);
		}
		i++;
	}
	return (0);
}

int	check_first_last_column(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.height - 1)
	{
		if (data->map.layout[i][0] != '1')
		{
			printf("\033[31mError\nThe Map must be closed (First column : Point[%d][%d])\n\033[0m",
				i, 0);
			ft_clean_data_and_exit(data);
		}
		i++;
	}
	i = 0;
	while (i < data->map.height - 1)
	{
		if (data->map.layout[i][ft_strlen(data->map.layout[i]) - 1] != '1')
		{
			printf("\033[31mError\nThe Map must be closed (Last column : Point[%d][%ld])\n\033[0m",
				i, ft_strlen(data->map.layout[i]) - 1);
			ft_clean_data_and_exit(data);
		}
		i++;
	}
	return (0);
}

int	ft_check_flag(int flag, t_data *data)
{
	if (flag == 0)
	{
		printf("\033[31mError\nMissing player's position\n\033[0m");
		return(ft_clean_data_and_exit(data));
	}
	else if (flag > 1)
	{
		printf("\033[31mError\nToo many player's positions. Extra at[%d][%d] Extra = %d\n\033[0m", data->map.player_i, data->map.player_j, flag - 1);
		return(ft_clean_data_and_exit(data));
	}
	else
		return (0);
}


int	check_player(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < (int)ft_strlen(data->map.layout[i]))
		{
			if (set_player_position(i, j, data))
				flag++;
			j++;
		}
		j = 0;
		i++;
	}
	ft_check_flag(flag, data);
	return (0);
}

int	set_player_position(int i, int j, t_data *data)
{
	if (data->map.layout[i][j] == 'N' || data->map.layout[i][j] == 'S'
		|| data->map.layout[i][j] == 'W' || data->map.layout[i][j] == 'E')
	{
		data->map.player_i = i;
		data->map.player_j = j;
		data->map.player_dir = data->map.layout[i][j];
		return (1);
	}
	else
		return (0);
}
