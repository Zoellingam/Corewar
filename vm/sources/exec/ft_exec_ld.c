/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 22:45:07 by igomez           ###   ########.fr       */
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
	Prend un paramètre quelconque et un registre.
	Charge la valeur du premier paramètre dans le registre.
	Son opcode est 10 en binaire, et il changera le carry.
42-EN:
	Take a random argument and a registry.
	Load the value of the first argument in the registry.
	Its opcode is 10 in binary and it will change the carry.
Epitech-FR:
	Cette instruction prend 2 paramètres le deuxième est forcement un
	registre (pas le PC). Elle load la valeur du premier paramètre dans le registre.
	Cette opération modifie le carry.
	ld 34,r3 charge les REG_SIZE octets a partir de l’adresse
	(PC + (34 % IDX_MOD))dans le registre r3.
*/
void		ft_exec_ld(t_vm *vm, t_process *process, t_instr *instr)
{
	int arg1;
	int arg2;

	/* 1st argument: T_DIR | T_IND */
	arg1 = instr->args[0].data;
	if (T_IND == instr->args[0].type)
		arg1 = ft_arena_get_int32(vm->visual.board.arena, process->pc + arg1 % IDX_MOD);
	/* 2nd argument: T_REG */
	arg2 = instr->args[1].data;

/*
	ft_printf("LD: arg1: %d (%02b) (%08x), arg2: %d (%02b)\n",
		arg1,
		instr->args[0].type,
		*(unsigned int *)(vm->visual.arena + process->pc),
		instr->args[1].data,
		instr->args[1].type);
*/
		
	/* Load the byte at the indexed position */
	process->reg[arg2] = arg1;
	/* Update the carry flag */
	process->carry = (0 == process->reg[arg2]);
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | ld %d r%hhd\n", process->number, arg1, arg2);
}
