/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 16:06:28 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"
#include "ft_parser.h"
#include "ft_asm.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

static void	ft_assemble(int fd, t_parser *parser)
{
	t_instr	*instr;
	t_list	*it;
	int		i;
	int8_t	c;

	/* Write the header in one block */
	write(fd, &parser->header, sizeof(t_header));

	/* For each statement parsed */
	it = parser->statement_head.next;
	while (it != &parser->statement_head)
	{
		/* get the encoded instruction */
		instr = C_STATEMENT(it)->instr;

		/* write the instruction number, using unsigned char type */
		c = instr->op->numero;
		write(fd, &c, sizeof(c));

		/* write the bytecode, already stored as unsigned char */
		if (0 != instr->op->param_byte)
			write(fd, &instr->bytecode, sizeof(instr->bytecode));

		/* for each paramaters of the instruction */
		i = 0;
		while (i < instr->op->nb_args)
		{
			/* Write the data with the size associed */
			write(fd, instr->args[i].data, instr->args[i].size);
			++i;
		}
		/* next instruction */
		it = it->next;
	}
}

void		ft_asm(char const *file_in, char const *file_content)
{
	t_string	*file_out;
	t_parser	parser;
	struct stat st;
	int			fd_out;

	/* Parse the file_content */
	if (0 != ft_parse(&parser, file_in, file_content))
	{
		/* Copy up to len - 2 chars to skip the '.s' suffix */
		file_out = ft_string_ndup(file_in, ft_strlen(file_in) - 2);
		/* add the suffix for compiled object */
		ft_string_cat(file_out, ".cor");
		/* Check if file exist and get the length. */
		if (0 <= stat(file_out->str, &st))
			ft_fprintf(ft_stderr, "File {red:%s} already exist\n", file_out->str);
		else
		{
			/* Try to open the destination file */
			fd_out = open(file_out->str, O_WRONLY | O_CREAT, 0644);
			if (0 > fd_out)
				ft_fprintf(ft_stderr, "Can't open destination file '%s'\n", file_out->str);
			else
			{
				/* Assemble the parsed code and close the file descriptor */
				ft_assemble(fd_out, &parser);
				close(fd_out);
			}
		}
		/* Cleanup memory */
		ft_parser_del(&parser);
		ft_string_del(&file_out);
	}
}
