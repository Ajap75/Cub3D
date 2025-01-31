	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:12 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/31 09:09:49 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	ft_set_north_texture(char *line, t_data *data)
{

	if (data->config.textures[0])
	{

		free(line);
		printf("\033[31mError:\nMultiple NORTH texture\n\033[0m");
		ft_clean_data_and_exit(data);
	}
	data->config.textures[0] = ft_strtrim(line, " NO\t\n");
	free(line);
	return(0);
}

int	ft_set_south_texture(char *line, t_data *data)
{
	if (data->config.textures[1])
	{
		free(line);
		printf("\033[31Error:\nMultiple SOUTH texture\n\033[0m");
		ft_clean_data_and_exit(data);

	}
	data->config.textures[1] = ft_strtrim(line, " SO\t\n");
	free(line);
	return(0);
}

int	ft_set_west_texture(char *line, t_data *data)
{

	if (data->config.textures[2])
	{
		free(line);
		printf("\033[31Error:\nMultiple WEST texture\n\033[0m");
		ft_clean_data_and_exit(data);

	}
	data->config.textures[2] = ft_strtrim(line, " \tWE\n");
	free(line);
	return(0);
}

int	ft_set_east_texture(char *line, t_data *data)
{
	if (data->config.textures[3])
	{
		free(line);
		printf("\033[31Error:\nMultiple EAST texture\n\033[0m");
		ft_clean_data_and_exit(data);

	}
	data->config.textures[3] = ft_strtrim(line, " \tEA\n");
	free(line);
	return(0);
}
