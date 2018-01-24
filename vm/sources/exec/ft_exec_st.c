/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_st.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/22 23:07:23 by igomez           ###   ########.fr       */
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
	Prend un registre et un registre ou un indirect, et stocke
	la valeur du registre vers le second paramètre. Son opcode
	est 0x03. Par exemple,
	st r1, 42 stocke la valeur de r1 à l’adresse (PC + (42 % IDX_MOD))
42-EN:
	take a registry and a registry or an indirect and store the
	value of the registry toward a second argument. Its opcode
	is 0x03. For example,
	st r1, 42 store the value of r1 at the address (PC + (42 % IDX_MOD))
Epitech-FR:
	Cette instruction prend 2 paramètres. Elle store (REG_SIZE OCTET)
	la valeur du premier argument (toujours un registre) dans le second.
	st r4,34 store la valeur de r4 a l’adresse ( PC + (34 % IDX_MOD))
	st r3,r8 copie r3 dans r8
*/
void		ft_exec_st(t_vm *vm, t_process *process, t_instr *instr)
{
	int arg1;
	int arg2;

	/* Make sure the instruction has the correct number of parameter */
	assert(2 == instr->op->nb_args);
	/* 1st argument: T_REG */
	arg1 = process->reg[instr->args[0].data];
	/* 2nd argument: T_IND | T_REG */
	arg2 = instr->args[1].data;
	if (T_REG == instr->args[1].type)
		process->reg[arg2] = arg1;
	/* We found a position, store in the arena */
	else
		ft_arena_set_int32(vm->arena, process->pc + arg2 % IDX_MOD, arg1);
	/* Display */
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | st r%hhd %d\n", process->number, instr->args[0].data, arg2);
}
