/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 23:54:51 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/13 03:12:46 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# define WIDTH 512
# define HEIGHT 512

# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../lib/libFT/include/libft.h"
# include "../lib/libmlx42/include/MLX42/MLX42.h"

typedef struct s_file
{
	char	*filetype;
	char	*filename;
}	t_file;

typedef struct s_images
{
	char			*name;
	mlx_image_t		*img;
	struct s_images	*prev;
	struct s_images	*next;
}	t_images;

t_images	*g_img;
typedef struct s_element
{
	char				type;
	int					x;
	int					y;
	struct s_element	*prev;
	struct s_element	*next;
}	t_element;

typedef struct s_map
{
	char			*name;
	t_element		*element;
	t_element		*last_element;
	int				width;
	int				height;
	struct s_map	*prev;
	struct s_map	*next;
	struct s_map	*last_map;
}	t_map;

t_map		*g_map;
typedef enum e_filetype
{
	ONLY_TEXTURES,
	ALL
}	t_filetype;

// main.c
mlx_t		*g_mlx;

enum e_jump
{
	NO_JUMP,
	JUMP,
	FALL
};

// error_handler.c
void		error(char *msg);
void		debug(const char *s, ...);
void		console(const char *s, ...);
void		*safe_calloc(size_t count, size_t size);

// files.c
void		load_files(int argc, char **argv);
void		load_texture_files(int fd, char *ptr);
void		read_files(char **ptr, void (*func)(int, char *));
char		*get_filename(char *ptr);

// maps.c
void		load_map_files(int fd, char *ptr);

// keys.c
void		keyhooks(mlx_key_data_t keydata, void *param);
void		loop(void *param);
void		jump_hook(void *param);

// player_moves.c
const bool	player_ml(void);
const bool	player_mu(void);
const bool	player_mr(void);
const bool	player_md(void);
int			g_jump;

// array_helpers.c
int			arr_position(int arr[], int key);

#endif