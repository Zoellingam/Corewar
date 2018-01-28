/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_eliminate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 18:58:50 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "libft.h"
#include "ft_round.h"
#include "ft_vm.h"

void 	ft_vm_eliminate(t_list *it, void *context)
{
	t_process	*process;
	t_vm		*vm;
	int			offset;

	vm = (t_vm *)context;
	process = C_PROCESS(it);
	offset = vm->round.cycle - process->last_live_cycle;
	/* If the process notified that he lived during the last round, we
	   need to reset that information. If he did not say live, we have
	   to delete the process and print his death on the correct verbosity */
	if (offset >= vm->round.cycle_to_die)
	{
		if (OPTION_DISPLAY_SHOW_DEATHS & ((t_vm *)context)->option.display)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				process->number, offset, vm->round.cycle_to_die);
		vm->visual.pc_position[process->pc] = 0;
		if (process->number == process->parent_number &&
			vm->option.display & OPTION_DISPLAY_SHOW_NCURSES)
			ft_visual_refresh_player_kill(&vm->visual, process);
		ft_process_del(it);
	}
	process->live_per_round = 0;
}
