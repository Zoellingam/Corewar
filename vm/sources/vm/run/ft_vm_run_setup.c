/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_run_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 00:19:36 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "libft.h"

void	ft_vm_run_setup(t_vm *this)
{
	/* if dump is unset, set it to -1. It will decrease infinitely and
	   have no effect on the engine, working the way it have to */
	if (0 == this->option.dump)
		--this->option.dump;
	/* if round limit is unset, set it to -1 for the same reason */
	if (0 == this->option.round_limit)
		--this->option.round_limit;
	/* Init round informations */
	ft_memset(&this->round, 0, sizeof(this->round));
	this->round.nbr_live = 0;
	this->round.cycle_to_die = CYCLE_TO_DIE;
	this->round.nb_check = 0;
	this->round.last_champion_alive = C_PROCESS(this->process_head.next)->number;	
}
