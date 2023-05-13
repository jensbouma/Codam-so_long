/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 17:23:15 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/13 11:16:03 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const bool	player_ml(void)
{
	ft_printf("Player moved left!\n");
	g_player->direction = LEFT;
	g_player->state = WALK;
	// if (g_img->img->instances[0].x > 0)
	// 	g_img->img->instances[0].x -= 5;
	return (true);
}

const bool	player_mu(void)
{
	ft_printf("Player moved up!\n");
	g_player->direction = UP;
	g_player->state = JUMP;
	// if (g_img->img->instances[0].y > 0)
	// {
	// 	if (g_jump == NO_JUMP)
	// 		g_jump = JUMP;
	// }

	return (true);
}

const bool	player_mr(void)
{
	ft_printf("Player moved right!\n");
	g_player->direction = RIGHT;
	g_player->state = WALK;
	// if (g_img->img->instances[0].x + g_img->img->width + 4 < g_mlx->width)
	// 		g_img->img->instances[0].x += 5;
	return (true);
}

const bool	player_md(void)
{
	ft_printf("Player moved down!\n");
	g_player->direction = DOWN;
	g_player->state = DUCK;
	// if (g_img->img->instances[0].y + g_img->img->height + 4 < g_mlx->height)
	// 	g_img->img->instances[0].y += 5;
	return (true);
}
