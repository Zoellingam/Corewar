/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 10:00:58 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "libft.h"

void		ft_vm_run(t_vm *this)
{
	int		limit;

	/* Cycle to die check limit */
	limit = 0;
	/* Setup the virtual machine */
	ft_vm_run_setup(this);
	/* Introduce contestants */
	ft_vm_introduce(this);
	/* Virtual machine run as long as there is processus alive */
	while (!ft_list_is_empty(&this->process_head))
	{
		++limit;
		/* Run cycle_to_die cycles. */
		if (!ft_vm_run_play(this))
			return ;
		/* If cycle to die is lower than the check counter, perform checks */
		if (this->round.cycle_to_die <= limit)
		{
			ft_vm_run_check(this);
			limit = 0;
		}
	}
	/* Announce Winner */
	ft_vm_announce(this);
}
