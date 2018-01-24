/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 23:19:02 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_process.h"
#include "ft_string.h"
#include "ft_vm.h"
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
	read(ch->fd, vm->arena + p->pc, ch->header.prog_size);
	close(ch->fd);
	/* Setup process numbers */
	p->number = ch->n;
	p->parent_number = p->number;
	/* Set champion number in first register */
	p->reg[1] = -p->number;
	/* Inc the total count of processes */
	++vm->nb_process;
	return (p);
}
