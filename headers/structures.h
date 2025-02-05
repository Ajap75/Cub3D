/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:42:38 by anastruc          #+#    #+#             */
/*   Updated: 2025/02/05 16:53:01 by anastruc         ###   ########.fr       */
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
	char *map_filename;
	char *textures[4]; /* NO, SO, WE, EA*/
	int	textures_files_fd[4]; /* NO, SO, WE, EA*/
	int	map_file_fd;
	int floor_color[3];   /* RGB */
	int ceiling_color[3]; /* RGB */
	int	metadata_count;
	int	flags[6];
}				t_config;

typedef struct s_map
{
	char **layout;   // 2D array for the map
	int	begin_map_index; // Index of the beginning of the map;
	int	end_map_index; // Index of the end of the map;
	int width;       // Map width
	int height;      // MAp height
	int player_i;    // player coordinate
	int player_j;    // player coordinate
	char player_dir; // player starting orientation
}				t_map;

typedef struct s_data
{
	t_config	config;
	t_map		map;
}				t_data;

#endif
