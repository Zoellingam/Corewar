/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_ldi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/23 12:44:00 by igomez           ###   ########.fr       */
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
	ldi, comme son nom l’indique, n’implique nullement de se
	 baigner dans de la crème de marrons, même si son opcode est 0x0a.
	Au lieu de ça, ca prend 2 index et 1 registre, additionne les 2 premiers,
	 traite ca comme une adresse, y lit une valeur de la taille d’un registre
	 et la met dans le 3eme.
42-EN:
	ldi, ldi, as per the name, does not imply to go
	 swimming in chestnut cream, even if its code is 0x0a. 
	Instead, it will use 2 indexes and 1 registry, adding the first two,
	 treating that like an address, reading a value of a registry’s size
	 and putting it on the third.
Epitech-FR:
	Cette opération modifie le carry.
	ldi 3,%4,r1 lit IND_SIZE octets a l’adresse et ajoute 4 a cette valeur.
		S = (PC + (3 % IDX_MOD)) + 4
	On lit REG_SIZE octet a l’adresse (PC + (S % IDX_MOD)) qu’on copie dans r1.
	Les paramètre 1 et 2 sont des index.
*/

void		ft_exec_ldi(t_vm *vm, t_process *process, t_instr *instr)
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
	process->reg[arg3] = ft_arena_get_int32(vm->arena, process->pc + total % IDX_MOD);
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
	{
		ft_printf("P% 5d | ldi %d %d r%d\n       | -> load ", process->number, arg1, arg2, arg3);
		ft_printf("from %d + %d = %d (with pc and mod %d)\n", arg1, arg2, total, process->pc + total % IDX_MOD);
	}
}
