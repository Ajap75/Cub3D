/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:09:17 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/21 13:11:47 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	skip_metadata(t_data *data)
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
		else if (line[0] == '\0' || line[0] == '\n' || line[0] == '\r'
			|| line[0] == '\t')
		{
			data->map.begin_map_index++;
			free(line);
			continue ;
		}
		else
			break ;
	}
	free(line);
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
	return (0);
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
	return (0);
}
