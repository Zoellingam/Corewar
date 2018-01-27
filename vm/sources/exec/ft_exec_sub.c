/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 18:18:57 by igomez           ###   ########.fr       */
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
	Pareil que add, mais l’opcode est 0b101, et utilise une soustraction.
42-EN:
	Same as add, but with the opcode est 0b101, and uses a substraction.
Epitech-FR:
	même que add mais soustrait
*/
void		ft_exec_sub(t_vm *vm, t_process *process, t_instr *instr)
{
	int 	arg1;
	int 	arg2;
	int		arg3;

	/* Take 3 registers */
	arg1 = instr->args[0].data;
	arg2 = instr->args[1].data;
	arg3 = instr->args[2].data;
	/* Sub first 2 registers and store result into third register */
	process->reg[arg3] = process->reg[arg1] - process->reg[arg2];
	/* Setup the carry flag as "true" if the result is 0. */
	process->carry = (0 == process->reg[arg3]);
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | sub r%hhd r%hhd r%hhd\n", process->number, arg1, arg2, arg3);
	(void)vm;
}
