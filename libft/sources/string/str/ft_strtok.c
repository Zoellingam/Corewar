/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 12:22:09 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char    *ft_strtok(char *p, char const *delim)
{
    static char     *lasts;
    register int    ch;

    if (0 == p)
	   p = lasts;
    while (42)
    {
        if (0 == (ch = *p++))
            return (0);
        if (0 == ft_strchr(delim, ch))
            break ;
    }
    --p;
    lasts = p + ft_strcspn(p, delim);
    if (0 != *lasts)
	   *lasts++ = 0;
    return (p);
}
