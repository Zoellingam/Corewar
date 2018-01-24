/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_aff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 10:31:48 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "ft_process.h"
#include "libft.h"
#include "ft_round.h"
#include "ft_vm.h"
#include "endian.h"
#include <assert.h>

/*
42-FR:
	L’opcode est 10 en hexadécimal.
	Il y a un octet de codage des paramètres, même si c’est un peu
	 bête car il n’y a qu’un paramètre, qui est un registre, dont
	 le contenu est interprété comme la valeur ASCII d’un caractère
	 à afficher sur la sortie standard.
	Ce code est modulo 256.
42-EN:
	The opcode is 10 in the hexadecimal.
	There is an argument’s coding byte, even if it’s a bit silly because
	 there is only 1 argument that is a registry, which is a registry, and
	 its content is interpreted by the character’s ASCII value to display
	 on the standard output.
	The code is modulo 256.
Epitech-FR:
	Cette instruction est suivi d’un octet de paramétrage pour décrire les paramètres.
	Elle prend en paramètre un registre et affiche le caractère dont le code ascii
	est présent dans ce registre. (un modulo 256 est applique au code ascii,
	le caractère est affiché sur la sortie standard)
	Ex : ld %52,r3 aff r3 affiche ’*’ sur la sortie standard
*/
void		ft_exec_aff(t_vm *vm, t_process *process, t_instr *instr)
{
	int8_t 	arg1;

	/* 1st argument: T_REG */
	arg1 = process->reg[instr->args[0].data] & 0xff;
	if (0 != vm->option.display_aff)
		ft_printf("Aff: %c\n", arg1);
}
