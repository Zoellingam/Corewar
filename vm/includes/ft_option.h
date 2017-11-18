/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 11:51:30 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTION_H
# define FT_OPTION_H

# include <stdint.h>
# include "ft_list.h"

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

typedef struct		s_champion_option
{
	int32_t			n;
	int32_t			fd;
	char			*file_name;
	t_list			list;
}					t_champion_option;

# define C_OPT_CHAMP(it)	CONTAINEROF(it, t_champion_option, list)

typedef struct		s_option
{
	int32_t			dump;
	t_list			champion_head;
	size_t			champion_count;
}					t_option;

/* Init option and parse arguments */
int					ft_argument_parser(t_option *opt, int argc, char * const *argv);

#endif
