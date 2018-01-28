/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_player.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:15:31 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_PLAYER_H
# define FT_VISUAL_PLAYER_H

# include <stdint.h>
# include <ncurses.h>

struct s_vm;
struct s_process;

typedef struct			s_visual_player
{
	WINDOW				*win[4];
}						t_visual_player;

void					ft_visual_init_player(t_visual_player *player, struct s_vm const *vm);

void					ft_visual_refresh_player(t_visual_player const *this, struct s_process const *process);

void					ft_visual_refresh_player_kill(t_visual_player const *this, struct s_process const *process);

#endif
