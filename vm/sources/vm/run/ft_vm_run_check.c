/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_run_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/26 01:30:14 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "libft.h"

void ft_vm_run_check(t_vm *this)
{
	++this->round.nb_check;
	/* Delete dead champions if any */
	ft_list_apply_data(&this->process_head, (void *)this, &ft_vm_eliminate);
	/* We reach the number of verification without any modification of cycle to die
       or if at least NBR_LIVE live have been executed */
	if (NBR_LIVE <= this->round.nbr_live || MAX_CHECKS == this->round.nb_check)
	{
		this->round.cycle_to_die -= CYCLE_DELTA;
		if (this->option.display & OPTION_DISPLAY_SHOW_CYCLES)
			ft_printf("Cycle to die is now %d\n", this->round.cycle_to_die);
		this->round.nb_check = 0;
	}
	/* Restart live count */
	this->round.nbr_live = 0;
}
