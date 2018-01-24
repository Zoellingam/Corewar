/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_state_machine.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/22 02:45:51 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTION_STATE_MACHINE_H
# define FT_OPTION_STATE_MACHINE_H

struct s_option;
struct s_option_parser;

typedef enum		e_option_state
{
	OPT_STATE_PROCESS_LIMIT = 0,
	OPT_STATE_ROUND_LIMIT,
	OPT_STATE_START_CYCLE,
	OPT_STATE_CHAMPION,
	OPT_STATE_DEFAULT,
	OPT_STATE_STEALTH,
	OPT_STATE_DISPLAY,
	OPT_STATE_NUMBER,
	OPT_STATE_DUMP,
	OPT_STATE_CTMO,
	OPT_STATE_S,
	OPT_STATE_N,
	OPT_STATE_A
}					t_option_state;

typedef void		(*t_state_machine)(struct s_option *, struct s_option_parser *);

void		ft_option_parse_a(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_n(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_s(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_dump(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_ctmo(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_number(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_default(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_display(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_stealth(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_champion(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_round_limit(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_start_cycle(struct s_option *this, struct s_option_parser *parser);
void		ft_option_parse_process_limit(struct s_option *this, struct s_option_parser *parser);

#endif
