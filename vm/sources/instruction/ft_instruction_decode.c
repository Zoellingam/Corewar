/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_decode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 00:26:33 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "libft.h"

int		ft_instruction_decode(t_instr *this, uint8_t opcode, uint32_t pc, uint8_t *arena)
{
	extern t_op		g_op_tab[17];
	uint8_t			bytecode;

	ft_memset(this, 0, sizeof(*this));
	/* Setup the op pointer */
	this->op = g_op_tab + opcode;
	/* get bytecode and setup pc to the first arg */
	if (0 != this->op->param_byte)
	{
		bytecode = arena[LOOP(pc + 1)];
		this->new_pc = pc + 2;
	}
	/* Else, create new one with default DIR_CODE */
	else
	{
		bytecode = DIR_CODE << 6;
		this->new_pc = pc + 1;
	}
	this->instr_size = this->new_pc - pc;
	/* parse instructions from the bytecode */
	return (ft_instruction_parse(this, arena, bytecode));
}
