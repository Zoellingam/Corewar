/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 10:31:44 by igomez           ###   ########.fr       */
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
	Opcode 4. Prend trois registres, additionne les 2 premiers,
	 et met le résultat dans le troisième, juste avant de modifier le carry.
42-EN:
	Opcode 4. Take three registries, add the first two,
	 and place the result in the third, right before modifying the carry.
Epitech-FR:
	Cette instruction prend 3 registres en paramètre,
	 additionne le contenu des 2 premiers et met le résultat dans le troisième.
	Cette opération modifie le carry. add r2,r3,r5 additionne r2 et r3 et mets le résultat dans r5
*/
void		ft_exec_add(t_vm *vm, t_process *process, t_instr *instr)
{
	int 	arg1;
	int 	arg2;
	int		arg3;

	/* 1st argument: T_REG */
	arg1 = instr->args[0].data;
	/* 2nd argument: T_REG */
	arg2 = instr->args[1].data;
	/* 3rd argument: T_REG */
	arg3 = instr->args[2].data;
	/* Add first 2 registers and store result into third register */
	process->reg[arg3] = process->reg[arg1] + process->reg[arg2];
	/* Setup the carry flag as "true" if the result is 0. */
	process->carry = (0 == process->reg[arg3]);
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | add r%hhd r%hhd r%hhd\n", process->number, arg1, arg2, arg3);
	return ;
	(void)vm;
}
