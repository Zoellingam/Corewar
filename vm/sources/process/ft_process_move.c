/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:03:54 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_process.h"
#include "ft_visual.h"
#include "ft_printf.h"
#include "ft_vm.h"

void	ft_process_move(t_vm *vm, t_process *process, t_instr *instr)
{
	int32_t	i;

	if (vm->option.display & OPTION_DISPLAY_SHOW_NCURSES
		&& process->number == process->parent_number)
		ft_visual_refresh_player(&vm->visual.player, process);
	

	/* Tricks to handle zjmp instruction */
	if (ZJMP_SUCCEED == instr->new_pc)
		return ;
	/* Display zaz output */
	if (vm->option.display & OPTION_DISPLAY_SHOW_PC_MOVEMENTS)
	{
		ft_printf("ADV %zu (0x%04x -> 0x%04x) ",
			instr->instr_size, process->pc, instr->instr_size + process->pc);
		i = 0;
		while (i < instr->instr_size)
		{
			/* Print '00' if stealth mode is ON */
			if (0 != vm->option.stealth)
				ft_printf("ff ");
			/* Else, print the correct byte */
			else
				ft_printf("%02hhx ", ft_arena_get_int8(vm->visual.board.arena, process->pc + i));
			++i;
		}
		ft_printf("\n");
	}
	/* Jump to the next instruction */
	vm->visual.board.pc_position[process->pc] = 0;
	process->pc = LOOP(process->pc + instr->instr_size);
	vm->visual.board.pc_position[process->pc] = process->parent_number;
}
