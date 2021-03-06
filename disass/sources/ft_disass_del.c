/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 13:00:23 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_string.h"
#include <unistd.h>

static void	ft_disass_del_label(t_list *it)
{
	t_label	*label;

	label = C_LABEL(it);
	ft_memdel((void **)&label);
}

static void	ft_disass_del_instr(t_list *it)
{
	t_instr_node	*instr;

	instr = C_INSTR(it);
	ft_instruction_del(&instr->instr);
	ft_memdel((void **)&instr);
}

void 		ft_disass_del(t_disass *dsm)
{
	close(dsm->fd_in);
	close(dsm->fd_out);
	ft_list_apply(&dsm->label_head, &ft_disass_del_label);
	ft_list_apply(&dsm->instr_head, &ft_disass_del_instr);
}
