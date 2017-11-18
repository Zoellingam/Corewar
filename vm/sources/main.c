/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 15:28:53 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_string.h"
#include "endian.h"
#include <unistd.h>

int		ft_champion_check_number(t_list *it, void const *data)
{
	return (*(int *)data == C_OPT_CHAMP(it)->n);
}

# define ENDIAN_CORRECTION(nb)	ft_endian_apply_conversion((void *)&nb, (uint32_t)nb, sizeof(nb))

static int	ft_champion_load_header(t_champion *champ, t_champion_option *ch_opt)
{
	read(ch_opt->fd, &champ->header, sizeof(champ->header));
	if (IS_LITTLE_ENDIAN)
	{
		ENDIAN_CORRECTION(champ->header.magic);
		ENDIAN_CORRECTION(champ->header.prog_size);
	}
	if (COREWAR_EXEC_MAGIC != champ->header.magic)
	{
		ft_fprintf(ft_stderr, "Error: %s magic number is wrong\n", champ->header.magic);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int			ft_champion_init(t_vm *vm, t_champion_option *ch_opt)
{
	int			arena_offset_position;
	int			retcode;
	int 		idx;


	/* Get the champion number */
	idx = ch_opt->n - 1;
	ft_printf("Champion %d: ", idx + 1);

	/* Create champion */
	vm->champion[idx].used = 1;
	
	/* Read header and check for magic_number correctness,
	   In case of error, free the allocated champion */
	retcode = ft_champion_load_header(&vm->champion[idx], ch_opt);
	if (EXIT_SUCCESS == retcode)
	{
		ft_printf("Magic: 0x%08x, Size: %d bytes, Name: \"%s\", Comment: \"%s\"\n",
			vm->champion[idx].header.magic,
			vm->champion[idx].header.prog_size,
			vm->champion[idx].header.prog_name,
			vm->champion[idx].header.comment);
	}
	close(ch_opt->fd);
	arena_offset_position = 0;
	return (retcode);
}

int		ft_champion_load(t_vm *vm, t_option *opt)
{
	t_list		*it;

	/* Create champions from cl parsing, first pass: creates with n arguments */
	it = opt->champion_head.next;
	while (it != &opt->champion_head)
	{
		if (0 != C_OPT_CHAMP(it)->n)
			ft_champion_init(vm, C_OPT_CHAMP(it));
		it = it->next;
	}
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_option	opt;
	t_vm		vm;

	ft_log("coucou\n");
	ft_log_open("test.log\n");
	ft_log("salut les potes\n");
	ft_log("coucou\n");
	ft_log_close();
	ft_memset(&vm, 0, sizeof(vm));
	if (EXIT_FAILURE == ft_argument_parser(&opt, argc, argv))
		return (EXIT_FAILURE);
	if (EXIT_FAILURE == ft_champion_load(&vm, &opt))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
