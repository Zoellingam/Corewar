/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_introduce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/02 22:48:12 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "libft.h"

void		ft_vm_introduce(t_vm *this)
{
	t_list		*it;
	t_process	*process;

	/* Loop over champions */
	it = this->process_head.prev;
	ft_printf("Introducing contestants...\n");
	while (it != &this->process_head)
	{
		process = C_PROCESS(it);
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			process->number,
			this->option.champion[process->number - 1]->header.prog_size,
			this->option.champion[process->number - 1]->header.prog_name,
			this->option.champion[process->number - 1]->header.comment);
		it = it->prev;
	}
}
