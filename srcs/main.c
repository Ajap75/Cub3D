/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:53:53 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/05 11:54:38 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TODO :

- CHECKER LES OVERFLOW AVEC LES COULEURS
PARSE LES EXTENSION DE FICHIER .CUB*/
#include "../headers/functions.h"
#include "../headers/structures.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("\033[31mUseError : %s\n, the prog as followed :  ./cub3d map.cub\033[0m\n", strerror(errno));
		return (1);
	}
	data.config.map_filename = argv[1];
	data.config.map_file_fd = ft_open_file(data.config.map_filename);
	if (data.config.map_file_fd == -1)
		exit(1);
	ft_initialize(&data);
	parse_metadata(&data);
	// parse_map(&data, fd);
	ft_clean_data_and_exit(&data);
	// test_parsing_metadata(&data);
}

void	test_parsing_metadata(t_data *data)
{
	printf("Floor color : R = %d, G = %d, B = %d\n",
		data->config.floor_color[0], data->config.floor_color[1],
		data->config.floor_color[2]);
	printf("Ceilling color : R = %d, G = %d, B = %d\n",
		data->config.ceiling_color[0], data->config.ceiling_color[1],
		data->config.ceiling_color[2]);
}

int	ft_open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("\033[31mError :%s\n The file doesn't exist or\
can not be open\033[0m\n",
				strerror(errno));
		return (-1);
	}
	else
		return (fd);
}

int	ft_clean_layout(t_data *data)
{
	int	i;
	printf("PROUT\n");
	i = 0;
	if (data == NULL || data->map.layout == NULL)
		return (1);
	while (i < data->map.height)
	{
		if (data->map.layout[i] != NULL)
			free(data->map.layout[i]);
		i++;
	}
	free(data->map.layout);
	data->map.layout = NULL;
	return (0);
}
int	ft_clean_data_and_exit(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(data->config.map_file_fd);
		if (line == NULL)
			break ;
		free(line);
	}
	while (i < 4)
	{
		if (data->config.textures_files_fd[i] != -1)
			close(data->config.textures_files_fd[i]);
		if (data->config.textures[i])
			free(data->config.textures[i]);
		i++;
	}
	ft_clean_layout(data);
	exit(1);
}

int	ft_initialize(t_data *data)
{
	int	i;

	i = 0;
	data->map.layout = NULL;
	data->map.begin_map_index = -1;
	data->config.metadata_count = 0;
	data->map.height = 0;
	data->map.width = 0;
	while (i < 4)
	{
		data->config.textures[i] = NULL;
		data->config.textures_files_fd[i] = -1;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		data->config.ceiling_color[i] = 0;
		data->config.floor_color[i] = 0;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		data->config.flags[i] = 0;
		i++;
	}
	return (1);
}

int	ft_end_file(t_data *data)
{
	char	*line;
	while (1)
	{
		line = get_next_line(data->config.map_file_fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(data->config.map_file_fd);
	printf("FILE CLOSED\n");
	return (0);
}
