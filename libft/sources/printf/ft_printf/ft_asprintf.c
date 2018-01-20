/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 22:01:39 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_asprintf(char **ptr, char const *format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = ft_vasprintf(ptr, format, ap);
	va_end(ap);
	return (result);
}
