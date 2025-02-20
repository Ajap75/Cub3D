/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:16 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/20 13:01:31 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	get_map_index(t_data *data)
{
	char	*line;

	printf("Map index = %d\n", data->map.begin_map_index);
	while (1)
	{
		line = get_next_line(data->config.map_file_fd);

		printf("LINE = %s\n", line);
		if (line == NULL)
		{
			printf("\033[31mUseError : NO_MAP or ERROR DURING OPENING\n\033[0m\n");
			ft_clean_data_and_exit(data);
		}
		else if (line[0] == '\0' || line[0] == '\n' || line[0] == '\r' || line[0] == '\t')
		{
			data->map.begin_map_index++;
			free(line);
			continue ;
		}
		else
			break ;
	}
	printf("FIRST LINE OF MAP IS \nLINE[%d]\n",
		data->map.begin_map_index);
	free(line);
	return (0);
}

char	*ft_trim_line(char *line)
{
	char	*trimmed;

	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, "\t\n\r");
	if (!trimmed)
		return (line);
	free(line);
	return (trimmed);
}

int	ft_calculate_map_height_and_width(t_data *data)
{
	char	*line;

	data->map.end_map_index = data->map.begin_map_index;
	while (1)
	{
		line = get_next_line(data->config.map_file_fd);
		if (line == NULL)
			break ;
		line = ft_trim_line(line);
		data->map.width = ft_strlen(line);
		if (line[0] != '\0' && line[0] != '\n' && line[0] != '\r')
		{
			data->map.end_map_index++;
			if (data->map.width < (int)ft_strlen(line))
				data->map.width = ft_strlen(line);
			free(line);
			continue ;
		}
		else
			break ;
	}
	if (line != NULL)
		free(line);
	data->map.height = data->map.end_map_index - data->map.begin_map_index;
	printf("Map Width = %d\n", data->map.width);
	printf("end_map_index = %d \nbegin_map_index = %d \n",
		data->map.end_map_index, data->map.begin_map_index);
	printf("Map Height = %d \n", data->map.height);
	return (0);
}

int	*ft_go_to_map(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (i < data->map.begin_map_index)
	{
		line = get_next_line(data->config.map_file_fd);
		if (line == NULL)
			break ;
		// printf("go tol map : line[%d] : |%s|\n",
		// 	i, line);
		free(line);
		i++;
	}
	return (0);
}

int	ft_initialize_layout(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.height)
	{
		data->map.layout[i] = NULL;
		i++;
	}
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

int	ft_store(t_data *data)
{
	ft_open_file(data->config.map_filename);
	printf("data->map.height = %d\n", data->map.height);
	data->map.layout = malloc(sizeof(char *) * data->map.height);
	if (data->map.layout == NULL)
	{
		printf("Error\nMallocError\n");
		ft_clean_data_and_exit(data);
	}
	ft_go_to_map(data);
	ft_fill_layout(data);
	print_map(data);
	return (0);
}
int	ft_store_map(t_data *data)
{
	ft_calculate_map_height_and_width(data);
	// skip_empty_line(data);
	ft_end_file(data);
	ft_store(data);
	return (0);
}

// int	ft_check_allowed_character(t_data *data)
// {

// }

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

int	check_boundaries(t_data *data)
{
	check_first_last_row(data);
	check_first_last_column(data);
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
int	replace_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < (int)ft_strlen(data->map.layout[i]))
		{
			if (data->map.layout[i][j] == ' ')
				data->map.layout[i][j] = '1';
			j++;
		}
		j = 0;
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

int	check_allowed_character(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < (int)ft_strlen(data->map.layout[i]))
		{
			if (data->map.layout[i][j] == 'N' || data->map.layout[i][j] == 'S'
				|| data->map.layout[i][j] == 'W'
				|| data->map.layout[i][j] == 'E'
				|| data->map.layout[i][j] == '1'
				|| data->map.layout[i][j] == '0')
				j++;
			else
			{
				printf("\033[31mError\nCharacter : |%c| Pos[%d][%d]Unauthorized\nAuthorized characters are : '1' '0' 'N' 'S' 'E' 'W'\n\033[0m",
					data->map.layout[i][j], i, j);
				ft_clean_data_and_exit(data);
			}
		}
		j = 0;
		i++;
	}
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

int skip_metadata(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (i < data->map.begin_map_index)
	{
		line = get_next_line(data->config.map_file_fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	return (0);
}
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
