/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/22 22:46:28 by igomez           ###   ########.fr       */
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
	Applique un & (ET bit-à-bit) sur les deux premiers paramètres,
	et stocke le résultat dans le registre qui est le 3ème paramètre.
	Opcode 0x06. Modifie le carry.
42-EN:
	Apply an & (bit-to-bit AND) over the first two arguments and store
	the result in a registry, which is the third argument.
	Opcode 0x06. Modifies the carry.
Epitech-FR:
	p1 & p2 -> p3 le paramètre 3 et toujours un registre.
	Cette opération modifie le carry. and r2, %0,r3 met r2 & 0 dans r3
*/
void		ft_exec_and(t_vm *vm, t_process *process, t_instr *instr)
{
	int 	arg1;
	int 	arg2;
	int		arg3;

	/* Make sure the instruction has the correct number of parameter */
	assert(3 == instr->op->nb_args);
	/* 1st argument: T_REG | T_DIR | T_IND */
	arg1 = instr->args[0].data;
	if (T_REG == instr->args[0].type)
		arg1 = process->reg[arg1];
	else if (T_IND == instr->args[0].type)
		arg1 = ft_arena_get_int32(vm->arena, process->pc + arg1 % IDX_MOD);
	/* 2nd argument: T_REG | T_IND | T_DIR */
	arg2 = instr->args[1].data;
	if (T_REG == instr->args[1].type)
		arg2 = process->reg[arg2];
	else if (T_IND == instr->args[1].type)
		arg2 = ft_arena_get_int32(vm->arena, process->pc + arg2 % IDX_MOD);
	/* 3rd argument: T_REG */
	arg3 = instr->args[2].data;
	/* Store result into third register */
	process->reg[arg3] = arg1 & arg2;
	/* Setup the carry flag as "true" if the result is 0. */
	process->carry = (0 == process->reg[arg3]);
	/* debug */
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | and %d %d r%hhd\n", process->number, arg1, arg2, arg3);
}
