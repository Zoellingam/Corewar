/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 12:10:09 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <assert.h>

size_t      ft_strcspn(char const *s, char const *reject)
{
    char const  *spanp;
    char const  *p;
    char        sc;
    char        c;

    p = s;
    while (42)
    {
        sc = 1;
        c = *p++;
        spanp = reject;
        while (0 != sc)
            if (c == (sc = *spanp++))
                return (p - 1 - s);
    }
    /* This return shouldn't be reachable in any way. */
    assert(0);
    return (0);
}
