/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_lld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 18:16:11 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_process.h"
#include "libft.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "endian.h"
#include <assert.h>

/*
42-FR:
	Signifie long-load, donc son opcode est évidemment 13.
	C’est la même chose que ld, mais sans % IDX_MOD. Modifie le carry
42-EN:
	Means long-load, so it’s opcode is obviously 13.
	It the same as ld, but without % IDX_MOD. Modify the carry.
Epitech-FR:
	Comme ld sans le %IDX_MOD Cette opération modifie le carry.
*/
void		ft_exec_lld(t_vm *vm, t_process *process, t_instr *instr)
{
	int arg1;
	int arg2;

	/* 1st argument: T_DIR | T_IND */
	arg1 = instr->args[0].data;
	if (T_IND == instr->args[0].type)
		arg1 = ft_arena_get_int32(vm->visual.arena, process->pc + arg1);
	/* 2nd argument: T_REG */
	arg2 = instr->args[1].data;

	/* Load the byte at the indexed position */
	process->reg[arg2] = arg1;
	/* Update the carry flag */
	process->carry = (0 == process->reg[arg2]);
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | lld %d r%hhd\n", process->number, arg1, arg2);
}
