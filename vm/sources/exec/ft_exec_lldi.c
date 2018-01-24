/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_lldi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 01:23:28 by igomez           ###   ########.fr       */
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
	Opcode 0x0e. Pareil que ldi, mais n’applique aucun modulo aux adresses.
	Modifiera, par contre, le carry.
42-EN:
	Opcode 0x0e. Same as ldi, but does not apply any modulo to the addresses.
	It will however, modify the carry.
Epitech-FR:
	Comme ldi sans le %IDX_MOD Cette opération modifie le carry.
*/
void		ft_exec_lldi(t_vm *vm, t_process *process, t_instr *instr)
{
	int arg1;
	int arg2;
	int arg3;
	int total;

	/* Make sure the instruction has the correct number of parameter */
	assert(3 == instr->op->nb_args);
	/* 1st argument: T_REG | T_DIR | T_IND */
	arg1 = instr->args[0].data;
	if (T_REG == instr->args[0].type)
		arg1 = process->reg[arg1];
	else if (T_IND == instr->args[0].type)
		arg1 = ft_arena_get_int32(vm->arena, process->pc + arg1 % IDX_MOD);
	/* 2nd argument: T_DIR | T_REG */
	arg2 = instr->args[1].data;
	if (T_REG == instr->args[1].type)
		arg2 = process->reg[arg2];
	/* 3rd argument: T_REG */
	arg3 = instr->args[2].data;
	total = arg1 + arg2;
	process->reg[arg3] = ft_arena_get_int32(vm->arena, process->pc + total);
	process->carry = (0 == process->reg[arg3]);
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
	{
		ft_printf("P% 5d | lldi %d %d r%d\n       | -> load ", process->number, arg1, arg2, arg3);
		ft_printf("from %d + %d = %d (with pc %d)\n", arg1, arg2, total, process->pc + total);
	}
}
