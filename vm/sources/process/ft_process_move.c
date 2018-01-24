/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 00:21:31 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_process.h"
#include "ft_printf.h"
#include "ft_vm.h"

void	ft_process_move(t_vm *vm, t_process *process, t_instr *instr)
{
	int32_t	i;

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
			ft_printf("%02x ", vm->arena[LOOP(process->pc + i)]);
			++i;
		}
		ft_printf("\n");
	}
	
	/* Jump to the next instruction */
	process->pc = LOOP(process->pc + instr->instr_size);
}