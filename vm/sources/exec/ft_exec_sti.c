/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 22:44:51 by igomez           ###   ########.fr       */
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
	Opcode 11. Prend un registre, et deux index (potentiellement des registres).
	Additionne les deux derniers, utilise cette somme comme une adresse ou sera
	copiée la valeur du premier paramètre.
42-EN:
	Opcode 11. Take a registry, and two indexes (potentially registries)
	add the two indexes, and use this result as an address where the
	value of the first parameter will be copied.
Epitech-FR:
	sti r2,%4,%5 sti copie REG_SIZE octet de r2 a l’adresse (4 + 5).
	Les paramètres 2 et 3 sont des index. Si les paramètres 2 ou 3
	sont des registres, on utilisera leur contenu comme un index,
*/
void		ft_exec_sti(t_vm *vm, t_process *process, t_instr *instr)
{
	int arg1;
	int arg2;
	int arg3;
	int total;

	/* 1st argument: T_REG */
	arg1 = process->reg[instr->args[0].data];
	/* 2nd argument: T_REG | T_DIR | T_IND */
	arg2 = instr->args[1].data;
	if (T_REG == instr->args[1].type)
		arg2 = process->reg[arg2];
	else if (T_IND == instr->args[1].type)
		arg2 = ft_arena_get_int32(vm->visual.board.arena, process->pc + arg2 % IDX_MOD);
	/* 3rd argument: T_DIR | T_REG */
	arg3 = instr->args[2].data;
	if (T_REG == instr->args[2].type)
		arg3 = process->reg[arg3];
	/* get the sum of arg 2 and 3  */
	total = arg2 + arg3;
	/* Set data in the arena */
	ft_arena_set_int32(&vm->visual, process->pc + total % IDX_MOD, arg1, process->parent_number);
	/* Final print */
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
	{
		ft_printf("P% 5d | sti r%hhd %d %d\n       | -> store to %d + %d = ",
			process->number,
			instr->args[0].data,
			arg2,
			arg3,
			arg2,
			arg3);
		ft_printf("%d (with pc and mod %d)\n",
			total,
			process->pc + total % IDX_MOD);
	}
}
