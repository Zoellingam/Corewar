/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_run_play.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 10:01:29 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "libft.h"

static int	ft_vm_dump(uint8_t *arena)
{
	size_t	i;

	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		ft_printf("%02hhx ", arena[i++]);
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
		return (ft_vm_dump(this->arena));
	++this->round.cycle;
	if (this->option.display & OPTION_DISPLAY_SHOW_CYCLES)
		ft_printf("It is now cycle %d\n", this->round.cycle);
	ft_list_apply_data(&this->process_head, (void *)this, &ft_process_play);
	return (1);
}
