/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_clone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 23:22:09 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_string.h"

t_process *ft_process_clone(t_process *this, int number, int32_t pc)
{
	t_process 	*p;

	/* Alloc a process and copy the data of the parent process */
	p = ft_memcpy(ft_memalloc(sizeof(*p)), this, sizeof(*p));
	/* Now, reset data that explicitely need to be */
	INIT_LIST_HEAD(p->list);
	p->number = number;
	p->opcode = 0;
	p->pc = pc;
	return (p);
}
