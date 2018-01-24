/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 22:01:36 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char const *format, ...)
{
	int		result;
	va_list	ap;


	va_start(ap, format);
	result = ft_vprintf(format, ap);
	va_end(ap);
	return (result);
}