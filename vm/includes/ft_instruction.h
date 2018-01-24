/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 01:25:22 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTRUCTION_H
# define FT_INSTRUCTION_H

# include <stddef.h>
# include "ft_arena.h"
# include "ft_exec.h"

# define OPCODE_IS_VALID(x)		(16 > (uint32_t)((x) - 1))
# define REG_IS_VALID(x)		(REG_NUMBER > (uint32_t)((x) - 1))

# define ZJMP_SUCCEED			0x0ff3e7

typedef struct		s_instr_decode
{
	t_arg_type		type;
	uint32_t		data;
	size_t			size;
}					t_instr_decode;

typedef struct		s_instr
{
	t_op			*op;
	int32_t			new_pc;
	int32_t			instr_size;
	t_instr_decode	args[4];
}					t_instr;

int					ft_instruction_decode(t_instr *this, uint8_t opcode, uint32_t pc, uint8_t *arena);

int					ft_instruction_parse(t_instr *this, uint8_t *arena, uint8_t bytecode);

#endif
