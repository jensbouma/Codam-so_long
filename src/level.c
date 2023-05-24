/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   level.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 20:16:27 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/24 23:35:50 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	level_tile(t_level *level, char *line, int y)
{
	t_tiles	*t;
	int		x;

	x = 0;
	while (line[x] != '\0' && line[x] != '\n')
	{
		t = (t_tiles *)memmory_alloccate(1, sizeof(*t));
		t->type = line[x];
		t->x = x;
		t->y = y;
		if (!level->tiles)
			level->tiles = t;
		else
		{
			t->prev = level->tiles;
			level->tiles_last->next = t;
		}
		level->tiles_last = t;
		x++;
	}
	level->w = x;
	level->h = y + 1;
}

void	*level_read(int fd, char *ptr)
{
	int			y;
	char		*line;
	t_level		*node;

	y = 0;
	node = (t_level *)memmory_alloccate(1, sizeof(*node));
	node->name = file_getname(ptr);
	line = get_next_line(fd);
	if (!line)
		error(ft_strjoin("Failed to read level: ", ptr));
	while (line)
	{
		level_tile(node, line, y++);
		free(line);
		line = get_next_line(fd);
	}
	return (node);
}

t_level	*level_default(void)
{
	t_level		*level;
	const char	*files[] = {\
		"./maps/valid.ber",
		"./maps/valid2.ber",
		NULL};

	print("No arguments given. Loading default maps...\n");
	level = file_open((char **)files, level_read);
	return (level);
}

t_image	*level_textures(t_game *game)
{
	const char	*files[] = {
		"textures/Base pack/Items/coinGold.png",
		"textures/Base pack/Items/coinGold.png",
		"textures/Base pack/Tiles/door_openMid.png",
		"textures/Base pack/Tiles/door_closedMid.png",
		"textures/Base pack/Tiles/castleCenter.png",
		"textures/Base pack/Tiles/grassCenter.png",
		NULL};

	return (texture_read_files(game, (char **)files, 1));
}

// Check if level is rectangular
// Check if level has all elements
// Check if level has valid elements
// Check if level has valid amount of elements
// Check if level has valid amount of collectibles
// Check if level has valid amount of exits
// Check if level has valid amount of players
// Check if level has valid amount of walls
// Check if level has valid amount of empty spaces
// Check if level has valid amount of enemies
