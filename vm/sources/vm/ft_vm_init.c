/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 00:18:53 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_vm.h"
#include "libft.h"
#include "op.h"

static void	ft_vm_init_create_processes(t_vm *this)
{
	t_process	*p;
	size_t		idx;

	/* Init processus list */
	INIT_LIST_HEAD(this->process_head);
	/* For each champions */
	idx = 0;
	while (idx < MAX_PLAYERS)
	{
		if (0 != this->option.champion[idx])
		{
			/* Create process and setup in arena */
			p = ft_process_new(this, idx);
			/* Add in front of list */
			ft_list_add(&p->list, &this->process_head);
		}
		++idx;
	}
}

void	ft_vm_init(t_vm *this, int argc, char **argv)
{
	ft_memset(this, 0, sizeof(*this));
	/* Parse options option */
	ft_option_init(&this->option, argc, argv);
	/* Create processus from options */
	ft_vm_init_create_processes(this);
}
