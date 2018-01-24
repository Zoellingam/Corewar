/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/23 23:43:07 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

struct s_vm;
struct s_instr;
struct s_process;
struct s_instr_decode;

typedef		void (*t_exec_instruction)(struct s_vm *,
									   struct s_process *,
									   struct s_instr *);

void		ft_exec_add(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_aff(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_and(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_fork(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_ld(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_ldi(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_lfork(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_live(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_lld(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_lldi(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_or(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_st(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_sti(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_sub(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_xor(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

void		ft_exec_zjmp(struct s_vm *vm,
						 struct s_process *process,
						 struct s_instr *instr);

#endif
