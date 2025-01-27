/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:53:53 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/27 18:00:37 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/structures.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc != 2)
	{
		strerror("Error : %s\n", "Use the prog as followed :  ./cub3d map.cub");
		return (1);
	}
	if (fd = open(argv[1], O_RDONLY))
		strerror("Error : %s\n", "The file doesn't exist or can not be open");
	parse_metadata(&data);
}
