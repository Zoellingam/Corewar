/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/22 16:33:19 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instruction.h"
#include "endian.h"
#include "libft.h"

static void	ft_instruction_parse_arg(t_instr *this, uint8_t *arena, int index)
{
	if (T_REG & this->args[index].type)
	{
		this->args[index].size = 1;
		this->args[index].data = (int32_t)ft_arena_get_int8(arena, this->new_pc);
	}
	else if ((T_IND & this->args[index].type) || 1 == this->op->has_index)
	{
		this->args[index].size = 2;
		this->args[index].data = (int32_t)ft_arena_get_int16(arena, this->new_pc);
	}
	else /* implicit T_DIR with int32 size */
	{
		this->args[index].size = 4;
		this->args[index].data = (int32_t)ft_arena_get_int32(arena, this->new_pc);
	}
	this->instr_size += this->args[index].size;
}

static int	ft_instruction_parse_data(t_instr *this, uint8_t *arena, uint8_t bytecode, int i)
{
	static t_arg_type	arg_array[] = { 0, T_REG, T_DIR, T_IND };

	/* Get type */
	this->args[i].type = arg_array[(bytecode >> 6) & 0x3];
	/* Abort if type is 0 */
	if (0 == this->args[i].type)
		return (0);
	/* Adjust data and size from type */
	ft_instruction_parse_arg(this, arena, i);
	/* Check if the parsed type is allowed by the instruction */
	if (0 == (this->args[i].type & this->op->arg_types[i]))
		return (0);
	/* Check if register number is valide */
	if ((T_REG & this->args[i].type) && !REG_IS_VALID(this->args[i].data))
		return (0);
	return (1);
}

int		ft_instruction_parse(t_instr *this, uint8_t *arena, uint8_t bytecode)
{
	int		i;
	int 	error;

	i = 0;
	error = 0;
	/* Parse each arg defined */
	while (i < this->op->nb_args)
	{
		/* Do not stop on error parsing. Because we need to get all info
		   from the arguments that fails in order to still perform a good
		   pc jump */
		if (!ft_instruction_parse_data(this, arena, bytecode, i))
			++error;
		/* Next loop, prepare bytecode, handle pc jump */
		bytecode <<= 2;
		this->new_pc += this->args[i].size;
		++i;
	}
	return (error);
}
