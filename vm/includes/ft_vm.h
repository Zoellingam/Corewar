/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 12:24:22 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VM_H
# define FT_VM_H

# include <stdint.h>
# include "ft_option.h"
# include "ft_list.h"
# include "op.h"

# ifdef DEBUG
#  define DEBUG_MODE 1
# else
#  define DEBUG_MODE 0
# endif

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

typedef struct		s_process
{
	uint8_t			*pc;
	uint8_t			reg[REG_NUMBER];
	uint8_t			carry;
	t_list			list;
}					t_process;

typedef struct		s_champion
{
	int				used;
	t_header		header;
	t_list			process_head;
}					t_champion;

typedef struct		s_vm
{
	t_champion		champion[MAX_PLAYERS];
	uint8_t			arena[MEM_SIZE];
	uint8_t			color[MEM_SIZE];
}					t_vm;

#endif
