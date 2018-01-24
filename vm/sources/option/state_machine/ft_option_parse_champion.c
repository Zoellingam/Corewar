/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse_champion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 19:46:31 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_state_machine.h"
#include "option/ft_option_parse.h"
#include "option/ft_option_usage.h"
#include "ft_option.h"
#include "endian.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

static void	ft_option_parse_champion_header(t_ch_opt *ch)
{
	read(ch->fd, &ch->header, sizeof(ch->header));
	if (IS_LITTLE_ENDIAN)
	{
		ch->header.magic = ft_endian_convert_uint32(ch->header.magic);
		ch->header.prog_size = ft_endian_convert_uint32(ch->header.prog_size);
	}
	/* Check for magic number */
	if (COREWAR_EXEC_MAGIC != ch->header.magic)
		ft_option_usage("Error: %s: magic number is wrong\n", ch->file_name);
	/* Check for prog_size correctness */
	if (CHAMP_MAX_SIZE < ch->header.prog_size)
		ft_option_usage("Error: %s: Too big: %d bytes (MAX: %d bytes)\n",
			ch->file_name,
			ch->header.prog_size,
			CHAMP_MAX_SIZE);
}

void		ft_option_parse_champion(t_option *this, t_option_parser *parser)
{
	t_ch_opt	*champ;
	char		*p;

	if (this->ch_count == MAX_PLAYERS)
		ft_option_usage("Error: No more than %d contestants\n", MAX_PLAYERS);
	/* Check for ".cor" suffix */
	p = *parser->argv;
	if (*(uint32_t *)".cor" != *(uint32_t *)(p + ft_strlen(p) - 4))
		ft_option_usage("File: %s is not well suffixed\n", p);
	/* Check for file validity */
	champ = &this->ch_opt[this->ch_count++];
	if ((uint32_t)champ->n > MAX_PLAYERS)
		ft_option_usage("Error: Incorrect champion number: %d\n", champ->n);
	/* Open file and read headers */
	champ->fd = open(p, O_RDONLY);
	champ->file_name = p;
	if (0 > champ->fd)
		ft_option_usage("Can't open file: %s\n", p);
	ft_option_parse_champion_header(champ);
	/* Unset the next_arg pointer (it is set when parsed with -n) */
	parser->next_arg = 0;
	/* Set back state to DEFAULT since we did good here */
	parser->state = OPT_STATE_DEFAULT;
	/* Skip argument */
	++parser->argv;
	--parser->argc;
}
