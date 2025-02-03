/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:30:16 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/03 19:37:57 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	get_map_index(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(data->config.map_file_fd);
		data->map.begin_map_index++;
		if (line == NULL)
		{
			printf("\033[31mUseError : NO_MAP or ERROR DURING OPENING\n\033[0m\n");
			ft_clean_data_and_exit(data);
		}
		else if (line[0] == '\0' || line[0] == '\n' || line[0] == '\r')
		{
			free(line);
			continue ;
		}
		else
			break ;
	}
	printf("FIRST LINE OF MAP IS \nLINE[%d] : |%s|\n",
		data->map.begin_map_index, line);
	free(line);
	return (0);
}


char *ft_trim_line(char *line)
{
	char	*trimmed;

	if (!line)
		return NULL;
	trimmed = ft_strtrim(line, "\t\n\r");
	if (!trimmed)
		return (line);
	free(line);
	return(trimmed);
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
		if (line[0] != '\0' && line[0] != '\n' && line[0] != '\r')
		{
			data->map.end_map_index++;
			if (data->map.width < (int)ft_strlen(line))
				data->map.width = ft_strlen(line);
			printf("Map Width = %d\n", data->map.height);
			free(line);
			continue ;
		}
		else
			break ;
	}
	if (line != NULL)
		free(line);
	data->map.height = data->map.end_map_index - data->map.begin_map_index + 1;
	printf("end_map_index = %d \nbegin_map_index = %d \n", data->map.end_map_index, data->map.begin_map_index);
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
		free(line);
		i++;
	}
	// printf(" I've reached the beginning of the map\nFirst line[%d] : |%s|\n",
	// 	i, line);
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
	int	i;

	i = 0;
	ft_initialize_layout(data);
	// printf("Line = %s\nSize = %ld\n" , line, ft_strlen(line));
	while (1)
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
		data->map.layout[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (data->map.layout[i] == NULL)
		{
			printf("Error\nMallocError\n");
			ft_clean_data_and_exit(data);
		}
		data->map.layout[i] = ft_strdup(line);
		printf("TAB line = |%s|\n", data->map.layout[i]);
		free(line);
	}
	ft_print_tab(data->map.layout);
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
int	parse_map(t_data *data)
{
	get_map_index(data);
	ft_end_file(data);
	data->config.map_file_fd = ft_open_file(data->config.map_filename);
	// printf("FD = %d\n", data->config.map_file_fd);
	ft_go_to_map(data);
	ft_store_map(data);
	return (0);
}

