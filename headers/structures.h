/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:42:38 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/28 12:32:17 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <../Libft/libft.h>
typedef struct s_config
{
	char *textures[4]; /* NO, SO, WE, EA*/

	int floor_color[3];   /* RGB */
	int ceiling_color[3]; /* RGB */
}				t_config;

typedef struct s_map
{
	char **layout;   // 2D array for the map
	int width;       // Map width
	int height;      // MAp height
	int player_x;    // player coordinate
	int player_y;    // player coordinate
	char player_dir; // player starting orientation
}				t_map;

typedef struct s_data
{
	t_config	config;
	t_map		map;
}				t_data;

#endif
