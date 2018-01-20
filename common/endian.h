/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 22:24:51 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENDIAN_H
# define ENDIAN_H

# include <stdint.h>
# include <stddef.h>

/*
 * brief	True if arch is big endian
 */
# define IS_BIG_ENDIAN		(*(uint16_t *)"\0\xff" < 0x100)

/*
 * brief	True if arch is little endian
 */
# define IS_LITTLE_ENDIAN	!IS_BIG_ENDIAN

/*
 * brief	Convert data to *buf as 1, 2, or 4 bytes type.
 */
void        ft_endian_apply_conversion(void *buf, uint32_t data, size_t n);

/*
 * brief    Bytes swap for int16_t
 */
int16_t		ft_endian_convert_int16(int16_t val);

/*
 * brief    Bytes swap for uint16_t
 */
uint16_t	ft_endian_convert_uint16(uint16_t val);

/*
 * brief    Bytes swap for int32_t
 */
int32_t		ft_endian_convert_int32(int32_t val);

/*
 * brief    Bytes swap for uint32_t
 */
uint32_t	ft_endian_convert_uint32(uint32_t val);

#endif

/*
#ifndef ENDIAN_H
# define ENDIAN_H

# include <stdint.h>

int			ft_is_little_endian(void);
int16_t		ft_endian_convert_int16(int16_t val);
int32_t		ft_endian_convert_int32(int32_t val);

#endif
*/
