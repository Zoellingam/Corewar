/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_zjmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 18:20:59 by igomez           ###   ########.fr       */
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
	Il n’y a jamais eu, n’y a pas, et n’y aura jamais d’octet de codage
	des paramètres derrière cette opération dont l’opcode est de 9.
	Elle prendra un index, et fait un saut à cette adresse si le carry est à 1
42-EN:
	there’s never been, isn’t and will never be an argument’s coding byte
	behind this operation where the opcode is 9. It will take an index and
	jump to this address if the carry is 1.
Epitech-FR:
	Cette instruction n’est pas suivie d’octet pour décrire les paramètres.
	Elle prend toujours un index (IND_SIZE) et fait un saut a cet index si
	le carry est a un. Si le carry est nul, zjmp ne fait rien mais consomme
	le même temps. zjmp %23 met si carry egale 1 met (PC + (23 % IDX_MOD)) dans le PC.
*/
void		ft_exec_zjmp(t_vm *vm, t_process *process, t_instr *instr)
{
	int		arg1;

	/* 1st argument: T_DIR */
	arg1 = instr->args[0].data;
	/* Exec jump if carry is valid */
	if (0 != process->carry)
	{
		instr->new_pc = ZJMP_SUCCEED;
		process->pc = LOOP(process->pc + arg1 % IDX_MOD);
		if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
			ft_printf("P% 5d | zjmp %hd OK\n", process->number, arg1);
	}
	/* Jump the current instruction on failure */
	else if (vm->option.display & OPTION_DISPLAY_SHOW_OPERATIONS)
		ft_printf("P% 5d | zjmp %hd FAILED\n", process->number, arg1);
}
