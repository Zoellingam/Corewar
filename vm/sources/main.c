/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/25 00:19:24 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

int		main(int argc, char **argv)
{
	t_vm	vm;

	/* Setup the virtual machine from command line arguments */
	ft_vm_init(&vm, argc, argv);
	/* Run the virtual machine. Let's fight. */
	ft_vm_run(&vm);
	/* Free memory */
	ft_vm_clear(&vm);
	return (0);
}
