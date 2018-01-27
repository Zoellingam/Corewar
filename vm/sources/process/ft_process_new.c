/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 19:28:11 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_process.h"
#include "ft_string.h"
#include "ft_vm.h"
#include "libft.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>

t_process	*ft_process_new(t_vm *vm, int champ_idx)
{
	extern t_op	g_op_tab[17];
	t_process	*p;
	t_ch_opt	*ch;

	p = ft_memalloc(sizeof(*p));
	/* get offset pc */
	p->pc = LOOP(MEM_SIZE / vm->option.ch_count * champ_idx);
	/* read the file */
	ch = vm->option.champion[champ_idx];
	/* Setup process numbers */
	p->number = ch->n;
	p->parent_number = p->number;
	/* read the file */
	read(ch->fd, vm->visual.arena + p->pc, ch->header.prog_size);
	close(ch->fd);
	/* fill color */
	ft_memset(vm->visual.color + p->pc, p->number, ch->header.prog_size);
	vm->visual.pc_position[p->pc] = p->parent_number;
	/* Set champion number in first register */
	p->reg[1] = -p->number;
	/* Inc the total count of processes */
	++vm->nb_process;
	return (p);
}
