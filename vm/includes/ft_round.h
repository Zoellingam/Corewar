/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 01:22:05 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ROUND_H
# define FT_ROUND_H

typedef struct		s_round
{
	/* Current cycle counter */
	int				cycle;
	/* Cycle to die decrement - Default CYCLE_TO_DIE */
	int				cycle_to_die;
	/* Cycle to die counter */
	int				cycle_to_die_check;
	/* nb live instruction executed since last check */
	int				nbr_live;
	/* Last champion alive */
	int				last_champion_alive;
	/* Check count */
	int 			nb_check;
}					t_round;

#endif
