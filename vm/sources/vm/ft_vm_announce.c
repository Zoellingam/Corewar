/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_announce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/25 23:36:06 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vm.h"

void	ft_vm_announce(t_vm *this)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
		this->round.last_champion_alive,
		this->option.champion[this->round.last_champion_alive - 1]->header.prog_name);
}
