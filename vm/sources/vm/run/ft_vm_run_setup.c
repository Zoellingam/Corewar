/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_run_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/26 01:30:21 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "libft.h"

void	ft_vm_run_setup(t_vm *this)
{
	/* Init round informations */
	ft_memset(&this->round, 0, sizeof(this->round));
	this->round.last_champion_alive = C_PROCESS(this->process_head.next)->number;	
	this->round.cycle_to_die = CYCLE_TO_DIE;
	this->round.cycle = this->option.start_cycle;
}
