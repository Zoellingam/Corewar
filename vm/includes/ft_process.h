/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 23:17:28 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESS_H
# define FT_PROCESS_H

# include <stdint.h>
# include "ft_list.h"
# include "op.h"

struct s_vm;
struct s_header;
struct s_instr;

typedef struct			s_process
{
	/* Process number */
	int32_t				number;
	/* Parent number is need for any update in visualisation mode */
	int32_t				parent_number;
	/* pc position in the arena */
	int32_t				pc;
	/* Register table */
	int32_t				reg[REG_NUMBER + 1];
	/* Carry flag */
	uint8_t				carry;
	/* Next operation index */
	int32_t				opcode;
	/* Process sleep cycles after any instruction */
	uint32_t			sleep;
	/* Process has lived */
	uint32_t			live_per_round;
	/* Last cycle process said sleep */
	uint32_t			last_live_cycle;
	/* List node */
	t_list				list;
}						t_process;

# define C_PROCESS(it)	CONTAINEROF(it, t_process, list)

/* Create processes from options */
t_process				*ft_process_new(struct s_vm *vm, int champ_idx);

/* Delete the process */
void					ft_process_del(t_list *it);

/* Play process */
void					ft_process_play(t_list *it, void *context);
void					ft_process_move(struct s_vm *vm, t_process *process, struct s_instr *instr);

t_process 				*ft_process_clone(t_process *this, int number, int32_t pc);

#endif
