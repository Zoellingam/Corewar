/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/22 02:45:34 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTION_H
# define FT_OPTION_H

# include "ft_list.h"
# include "op.h"

# define OPTION_DISPLAY_SHOW_LIVES				(1 << 0)
# define OPTION_DISPLAY_SHOW_CYCLES				(1 << 1)
# define OPTION_DISPLAY_SHOW_OPERATIONS			(1 << 2)
# define OPTION_DISPLAY_SHOW_DEATHS				(1 << 3)
# define OPTION_DISPLAY_SHOW_PC_MOVEMENTS		(1 << 4)
# define OPTION_DISPLAY_SHOW_NCURSES			(1 << 5)

typedef struct		s_ch_opt
{
	/* champion number (negative) */
	int				n;
	/* champion valide file descriptor, need to be closed */
	int				fd;
	/* champion header */
	t_header		header;
	/* champion file name */
	char			*file_name;
}					t_ch_opt;

# define C_OPT_CHAMP(it)	CONTAINEROF(it, t_ch_opt, list)

typedef struct		s_option
{
	/* Print memory and pause after N cycles */
	int				s;
	/* Champion use their memory for N cycles instead of global Arena memory */
	int				ctmo;
	/* Print memory and quit after N cycles */
	int				dump;
	/* Display binary mode */
	int				display;
	/* Boolean, display aff instruction */
	int 			display_aff;
	/* Memory stealh mode */
	int				stealth;
	/* Start at cycle N. Apply decrementation of cycle_to_die */
	int				start_cycle;
	/* Play only N round */
	int 			round_limit;
	/* Maximum of N processes in pool */
	int				process_limit;
	/* Arguments parsed */
	t_ch_opt		ch_opt[MAX_PLAYERS];
	t_ch_opt		*champion[MAX_PLAYERS];
	size_t			ch_count;
}					t_option;

/* Init option and parse arguments */
void				ft_option_init(t_option *this, int argc, char **argv);

/* Log option object */
void				ft_option_log(t_option *this);

#endif
