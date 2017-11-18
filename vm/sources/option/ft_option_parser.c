/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 11:52:26 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_printf.h"
#include "ft_string.h"
#include "ft_ctype.h"
#include "op.h"
#include <fcntl.h>
#include <unistd.h>

static char const	g_subject_usage[] =
{
	"./vm/corewar [-dump nbr_cycles] [[-n number] champion1.cor] ..."
};

# define VM_USAGE_BUFFER	(1 << 12)

static int	ft_print_usage(char const *format, ...)
{
	static char	buf[VM_USAGE_BUFFER];
	int			len;
	va_list		ap;

	if (0 != format)
	{
		va_start(ap, format);
		len = ft_vsprintf(buf, format, ap);
		va_end(ap);
		write(ft_stderr, buf, len);
	}
	ft_fprintf(ft_stderr, "Usage: %s\n", g_subject_usage);
	return (EXIT_FAILURE);
}

static int	ft_fast_atoi(char const *p)
{
	int32_t	x;

	x = 0;
	while (0 != ft_isdigit(*p))
	{
		x = (x << 3) + (x << 2) + (p[0] - '0');
		++p;
	}
	return (x);
}

static int	ft_argument_check_number(t_list *it, void const *data)
{
	return (*(int *)data == C_OPT_CHAMP(it)->n);
}

#define IS_SUFFIX(x)	(*(int *)".cor" == *(int *)((x) - 4 + ft_strlen(x)))

int			ft_argument_parser(t_option *option, int argc, char * const *argv)
{
	t_champion_option	*champ;
	int 				n;
	int					fd;

	/* Print usage if not enough arguments */
	if (2 > argc)
		return (ft_print_usage("Error: Not enough arguments\n"));
	/* Init option structure */
	option->dump = 0;
	option->champion_count = 0;
	INIT_LIST_HEAD(option->champion_head);

	/* For each arguments */
	while (0 != *++argv)
	{
		if (0 == ft_strcmp("-dump", *argv))
		{
			if (0 != option->dump)
				return (ft_print_usage("Error: -dump already declared\n"));
			if (0 == argv[1])
				return (ft_print_usage("Error: -dump argument is missing\n"));
			option->dump = ft_fast_atoi(*++argv);
			continue ;
		}
		n = 0;
		if (0 == ft_strcmp("-n", *argv))
		{
			if (0 == argv[1])
				return (ft_print_usage("Error: -n argument is missing\n"));
			if (0 == argv[2])
				return (ft_print_usage("Error: Champion is missing\n"));
			n = ft_fast_atoi(*++argv);
			if (MAX_PLAYERS < n || 1 > n)
				return (ft_print_usage("Error: Champion's number not in range 1-%d\n", MAX_PLAYERS));
			if (0 != ft_list_find_data(&option->champion_head,
									   (void *)&n,
									   &ft_argument_check_number))
				return (ft_print_usage("Error: Champion %d already defined\n", n));
			++argv;
		}
		if (0 == IS_SUFFIX(*argv))
			return (ft_print_usage("Error: %s is not a valide champion\n", *argv));
		fd = open(*argv, O_RDONLY);
		if (0 > fd)
			return (ft_print_usage("Error: Champion %s does not exist\n", *argv));
		champ = ft_calloc(1, sizeof(*champ));
		champ->n = n;
		champ->file_name = *argv;
		champ->fd = fd;
		ft_list_add(&champ->list, &option->champion_head);
		++option->champion_count;
	}
	if (0 != ft_list_is_empty(&option->champion_head))
		return (ft_print_usage("Error: Champion is missing\n"));
	return (EXIT_SUCCESS);
}
