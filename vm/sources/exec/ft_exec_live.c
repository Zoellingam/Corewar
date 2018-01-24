/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 01:22:39 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_process.h"
#include "libft.h"
#include "ft_round.h"
#include "ft_vm.h"
#include <assert.h>


/*
42-FR:
	L’instruction qui permet à un processus de rester vivant.
	A également pour effet de rapporter que le joueur dont le numéro est en paramètre est en vie.
	Pas d’octet de codage des paramètres, opcode 0x01.
	Oh, et son seul paramètre est sur 4 octets.
42-EN:
	The instruction that allows a process to stay alive.
	It can also record that the player whose number is the argument is indeed alive.
	No argument’s coding byte, opcode 0x01. Oh and its only argument is on 4 bytes.
Epitech-FR:
	Suivie de 4 octets qui représente le numéro du joueur.
	Cette instruction indique que ce joueur est en vie.
	(pas d’octet de codage des paramètres).
*/
void		ft_exec_live(t_vm *vm, t_process *process, t_instr *instr)
{
	size_t	i;
	int		arg1;

	/* Make sure the instruction has the correct number of parameter */
	assert(1 == instr->op->nb_args);
	/* 1st argument: T_DIR */
	arg1 = instr->args[0].data;

	if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | live %d\n", process->number, arg1);
	i = 0;
	/* Check if the target champion is correct from our champion list */
	while (i < vm->option.ch_count)
	{
		/* Check if any number match */
		if (-arg1 == vm->option.ch_opt[i].n)
		{
			if (vm->option.display & OPTION_DISPLAY_SHOW_LIVES)
				ft_printf("Player %d (%s) is said to be alive\n",
					-arg1, vm->option.champion[i]->header.prog_name);
			vm->round.last_champion_alive = -arg1;
			break ;
		}
		++i;
	}
	++vm->round.nbr_live;
	process->last_live_cycle = vm->round.cycle;
}
