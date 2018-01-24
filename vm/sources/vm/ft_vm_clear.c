/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/25 00:22:14 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_visual.h"
#include "ft_vm.h"

void	ft_vm_clear(t_vm *this)
{
	ft_list_apply(&this->process_head, &ft_process_del);
	/* close ncurse mode */
	if (this->option.display & OPTION_DISPLAY_SHOW_NCURSES)
		ft_visual_end();
}
