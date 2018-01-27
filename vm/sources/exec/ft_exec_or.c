/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 18:18:40 by igomez           ###   ########.fr       */
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
	Cette opération est un OU bit-à-bit, suivant le même principe
	que and, son opcode est donc évidemment 7.
42-EN:
	This operation is an bit-to-bit OR, in the same spirit and
	principle of and, its opcode is obviously 7.
Epitech-FR:
	même que and mais avec le ou ( | du c).
*/
void		ft_exec_or(t_vm *vm, t_process *process, t_instr *instr)
{
	int 	arg1;
	int 	arg2;
	int		arg3;

	/* 1st argument: T_REG | T_DIR | T_IND */
	arg1 = instr->args[0].data;
	if (T_REG == instr->args[0].type)
		arg1 = process->reg[arg1];
	else if (T_IND == instr->args[0].type)
		arg1 = ft_arena_get_int32(vm->visual.arena, process->pc + arg1 % IDX_MOD);
	/* 2nd argument: T_REG | T_IND | T_DIR */
	arg2 = instr->args[1].data;
	if (T_REG == instr->args[1].type)
		arg2 = process->reg[arg2];
	else if (T_IND == instr->args[1].type)
		arg2 = ft_arena_get_int32(vm->visual.arena, process->pc + arg2 % IDX_MOD);
	/* 3rd argument: T_REG */
	arg3 = instr->args[2].data;
	/* Store result into third register */
	process->reg[arg3] = arg1 | arg2;
	/* Setup the carry flag as "true" if the result is 0. */
	process->carry = (0 == process->reg[arg3]);
	/* debug */
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | or %d %d r%hhd\n",
			process->number, arg1, arg2, arg3);
}
