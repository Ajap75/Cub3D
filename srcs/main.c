/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:53:53 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/28 12:23:13 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/structures.h"
#include "../headers/functions.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc != 2)
	{
		printf("\033[31mUseError : %s\n, the prog as followed :  ./cub3d map.cub\033[0m\n", strerror(errno));
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd)
	{
		printf("\033[31mError : %s\n The file doesn't exist or can not be open\033[0m\n", strerror(errno));
		return (1);
	}
	parse_metadata(&data, fd);
	test_parsing_metadata(&data);
	// parse_map(&data, fd);
}

void	test_parsing_metadata(t_data *data)
{
	printf("Floor color : R = %d, G = %d, B = %d", data->config.floor_color[0],
		data->config.floor_color[1], data->config.floor_color[2]);
	printf("Ceilling color : R = %d, G = %d, B = %d",
		data->config.ceiling_color[0], data->config.ceiling_color[1],
		data->config.ceiling_color[2]);
	printf("Ceilling color : R = %d, G = %d, B = %d",
		data->config.ceiling_color[0], data->config.ceiling_color[1],
		data->config.ceiling_color[2]);
}
