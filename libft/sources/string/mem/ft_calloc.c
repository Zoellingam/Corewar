/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/04 14:21:50 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
**	Malloc errors aren't catched as long as the standards does not define
**	these kind of behaviors:
**    - https://linux.die.net/man/3/malloc
**    - http://linuxfr.org/users/gouttegd/journaux/gestion-des-erreurs-d-allocation-memoire-en-c
*/
void    *ft_calloc(size_t nb, size_t size)
{
    return (ft_memalloc(nb * size));
}
