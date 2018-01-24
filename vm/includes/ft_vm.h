/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 20:43:49 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VM_H
# define FT_VM_H

# include <stddef.h>
# include "ft_option.h"
# include "ft_round.h"
# include "ft_list.h"

typedef struct		s_vm
{
	t_round			round;
	t_option		option;
	uint8_t			arena[MEM_SIZE];
	int				nb_process;
	t_list			process_head;
}					t_vm;

/* Create processes from options */
void				ft_vm_init(t_vm *this, int argc, char **argv);

/* main loop engine */
void				ft_vm_run(t_vm *this);
int					ft_vm_run_play(t_vm *this);
void				ft_vm_run_setup(t_vm *this);
void				ft_vm_run_check(t_vm *this);

/* Delete the virtual machine */
void				ft_vm_clear(t_vm *this);

/* Introduce players */
void				ft_vm_introduce(t_vm *this);

/* Announce corewar winner */
void				ft_vm_announce(t_vm *this);

/* Check if champions are alive every CICLE_TO_DIE */
void 				ft_vm_eliminate(t_list *it, void *context);

#endif
