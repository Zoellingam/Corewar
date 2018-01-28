/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_play.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 02:30:24 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_process.h"
#include "ft_visual.h"
#include "libft.h"
#include "ft_exec.h"
#include "ft_vm.h"
#include "op.h"

static const t_exec_instruction	g_exec_instruction[] =
{
	0,
	&ft_exec_live,
	&ft_exec_ld,
	&ft_exec_st,
	&ft_exec_add,
	&ft_exec_sub,
	&ft_exec_and,
	&ft_exec_or,
	&ft_exec_xor,
	&ft_exec_zjmp,
	&ft_exec_ldi,
	&ft_exec_sti,
	&ft_exec_fork,
	&ft_exec_lld,
	&ft_exec_lldi,
	&ft_exec_lfork,
	&ft_exec_aff
};

void	ft_process_play(t_list *it, void *context)
{
	extern t_op		g_op_tab[17];
	t_instr			instr;
	t_process		*process;
	t_vm			*vm;

	vm = (t_vm *)context;
	process = C_PROCESS(it);
	if (!OPCODE_IS_VALID(process->opcode))
	{
		process->opcode = ft_arena_get_int8(vm->visual.arena, process->pc);
		if (!OPCODE_IS_VALID(process->opcode))
		{
			process->pc = LOOP(process->pc + 1);
			return ;
		}
		process->sleep = g_op_tab[process->opcode].nb_cycles;
	}
	if (0 == --process->sleep)
	{
		if (!ft_instruction_decode(&instr, process->opcode, process->pc, vm->visual.arena))
			g_exec_instruction[instr.op->numero](vm, process, &instr);
		/* Update pc and sleep */
		ft_process_move(vm, process, &instr);
		process->opcode = 0;
	}
}
