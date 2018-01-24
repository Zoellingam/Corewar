/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_run_play.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 13:55:49 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "libft.h"
#include <stdio.h>

static int	ft_vm_dump(t_vm *this)
{
	size_t	i;

	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		/* Print '00' if stealth mode is ON */
		if (0 != this->option.stealth)
			ft_printf("00 ");
			/* Else, print the correct byte */
		else
			ft_printf("%02hhx ", this->arena[i]);
		++i;
		if (0 == (i & 63))
			ft_printf("\n");
		if (0 == (i & 63) && 0 != i % MEM_SIZE)
			ft_printf("0x%04x : ", i);
	}
	return (0);
}

int			ft_vm_run_play(t_vm *this)
{
	if (this->option.dump == this->round.cycle)
		return (ft_vm_dump(this));
	if (this->option.s == this->round.cycle)
	{
		ft_vm_dump(this);
		getchar();
	}
	++this->round.cycle;
	if (this->option.display & OPTION_DISPLAY_SHOW_CYCLES)
		ft_printf("It is now cycle %d\n", this->round.cycle);
	ft_list_apply_data(&this->process_head, (void *)this, &ft_process_play);
	return (1);
}
