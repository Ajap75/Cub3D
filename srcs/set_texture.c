/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:12 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/30 18:16:52 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/colors.h"
#include "../headers/functions.h"
#include "../headers/structures.h"

int	ft_set_north_texture(char *line, t_data *data)
{

	if (data->config.textures[0])
	{
		ft_clean(data);
		free(line);
		exit(printf("\033[31mError:\nMultiple NORTH texture\n\033[0m"));
	}
	data->config.textures[0] = ft_substr(line, 3, ((int)ft_strlen(line) - 4));
	free(line);
	return(0);
}

int	ft_set_south_texture(char *line, t_data *data)
{
	if (data->config.textures[1])
	{
		ft_clean(data);
		free(line);
		exit(printf("\033[31Error:\nMultiple SOUTH texture\n\033[0m"));
	}
	data->config.textures[1] = ft_substr(line, 3, ((int)ft_strlen(line) - 4));
	free(line);
	return(0);
}

int	ft_set_west_texture(char *line, t_data *data)
{
	char *tmp;
	char *trimed;
	if (data->config.textures[2])
	{
		ft_clean(data);
		free(line);
		exit(printf("\033[31Error:\nMultiple WEST texture\n\033[0m"));
	}
	data->config.textures[2] = ft_substr(line, 3, ((int)ft_strlen(line) - 4));
	free(line);
	tmp = data->config.textures[2];
	//////LAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA?????????????
	// trimed = ft_strtrim(data->config.textures[2], " ");
	// ft_strlcpy(data->config.textures[2], trimed, ft_strlen(trimed));
	// free(tmp);
	// free(trimed);
	return(0);
}

int	ft_set_east_texture(char *line, t_data *data)
{
	if (data->config.textures[3])
	{
		ft_clean(data);
		free(line);
		exit(printf("\033[31Error:\nMultiple EAST texture\n\033[0m"));
	}
	data->config.textures[3] = ft_substr(line, 3, ((int)ft_strlen(line) - 4));
	free(line);
	return(0);
}
