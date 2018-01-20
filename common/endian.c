/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 22:24:46 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "endian.h"

void        ft_endian_apply_conversion(void *buf, uint32_t data, size_t n)
{
    if (1 == n)
        *(uint8_t *)buf = (uint8_t)data;
    else if (2 == n)
        *(uint16_t *)buf = ft_endian_convert_uint16((uint16_t)data);
    else if (4 == n)
        *(uint32_t *)buf = ft_endian_convert_uint32(data);
}

uint16_t	ft_endian_convert_uint16(uint16_t val) 
{
    return ((val << 8) | (val >> 8));
}

int16_t	    ft_endian_convert_int16(int16_t val) 
{
    return ((val << 8) | ((val >> 8) & 0xff));
}

uint32_t	ft_endian_convert_uint32(uint32_t val)
{
    val = ((val << 8) & 0xff00ff00) | ((val >> 8) & 0xff00ff); 
    return ((val << 16) | (val >> 16));
}

int32_t		ft_endian_convert_int32(int32_t val)
{
    val = ((val << 8) & 0xff00ff00) | ((val >> 8) & 0xff00ff); 
    return ((val << 16) | ((val >> 16) & 0xffff));
}

/* 
#include "endian.h"

int         ft_is_little_endian(void)
{
    union u_byte16 {
        uint16_t    i;
        uint8_t     c[2];
    } x = { 0x100 };
    return (0[x.c]);
}

int16_t     ft_endian_convert_int16(int16_t val) 
{
    union u_byte16 {
        uint16_t    i;
        uint8_t     c[2];
    } x = { val };
    x.c[0] ^= x.c[1] ^= x.c[0] ^= x.c[1];
    return (x.i);
}

int32_t     ft_endian_convert_int32(int32_t val)
{
    union u_byte32 {
        uint32_t    i;
        uint8_t     c[4];
    } x = { val };
    x.c[0] ^= x.c[3] ^= x.c[0] ^= x.c[3];
    x.c[1] ^= x.c[2] ^= x.c[1] ^= x.c[2];
    return (x.i);
}
*/
