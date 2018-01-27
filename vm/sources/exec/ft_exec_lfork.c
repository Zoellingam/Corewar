/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_lfork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 19:33:06 by igomez           ###   ########.fr       */
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
	Ca signifie long-fork, pour pouvoir fourcher de la paille à une
	distance de 15 mètres, exactement comme son opcode. Pareil qu’un
	fork sans modulo à l'adresse.
42-EN:
	means long-fork, to be able to fork abut straw from a distance of
	15 meters, exactly like with its opcode. Same as a fork without
	modulo in the address.
Epitech-FR:
	Comme fork sans le %IDX_MOD Cette opération modifie le carry.
*/
void		ft_exec_lfork(t_vm *vm, t_process *process, t_instr *instr)
{
	t_process	*p;
	int 		arg1;

	/* 1st argument: T_DIR */
	arg1 = instr->args[0].data;
	/* Do not create any champion if the process limit is reached */
	if (vm->nb_process != vm->option.process_limit)
	{
		p = ft_process_clone(process, ++vm->nb_process, LOOP(process->pc + arg1));
		vm->visual.pc_position[p->pc] = p->parent_number;
		ft_list_add(&p->list, &vm->process_head);
	}
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | lfork %d (%d)\n", process->number, arg1, process->pc + arg1);
}
