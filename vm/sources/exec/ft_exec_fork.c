/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 11:42:57 by igomez           ###   ########.fr       */
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
	Pas d’octet de codage des paramètres, prend un index, opcode 0x0c.
	Crée un nouveau processus, qui hérite des différents états de son père,
	à part son PC, qui est mis à (PC + (1er paramètre % IDX_MOD))
42-EN:
	there is no argument’s coding byte, take an index, opcode 0x0c.
	Create a new process that will inherit the different states of its father,
	except its PC, which will be put at (PC + (1st parameter % IDX_MOD)).
Epitech-FR:
	Cette instruction n’est pas suivie d’octet pour décrire les paramètres.
	Elle prend toujours un index et crée un nouveau programme qui s’exécute
	a partir de l’adresse: (PC + (premier paramètre % IDX_MOD)).
	Fork %34 crée un nouveau programme qui herite des différents états du père.
*/
void		ft_exec_fork(t_vm *vm, t_process *process, t_instr *instr)
{
	t_process	*p;
	int 		arg1;

	/* 1st argument: T_DIR */
	arg1 = instr->args[0].data;
	/* Clone process if the process limit is not reached */
	if (vm->nb_process != vm->option.process_limit)
	{
		p = ft_process_clone(process, ++vm->nb_process, LOOP(process->pc + arg1 % IDX_MOD));
		ft_list_add(&p->list, &vm->process_head);
	}
	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | fork %d (%d)\n", process->number, arg1, process->pc + arg1 % IDX_MOD);
}
