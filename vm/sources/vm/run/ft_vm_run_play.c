/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_run_play.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 16:58:02 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_process.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "libft.h"
#include <stdio.h>

static int	ft_vm_dump(t_vm *this)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (MEM_SIZE >> 6))
	{
		j = 0;
		ft_printf("0x%04x : ", i << 6);
		while (j < 64)
		{
			/* Print '00' if stealth mode is ON */
			if (0 != this->option.stealth)
				ft_printf("ff ");
			/* Else, print the correct byte */
			else
				ft_printf("%02hhx ", ft_arena_get_int8(this->visual.arena, (i << 6) + j));
			++j;
		}
		ft_printf("\n");
		++i;
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
