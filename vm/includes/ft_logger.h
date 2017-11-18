/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logger.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 13:24:02 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOGGER_H
# define FT_LOGGER_H

void	ft_log_assign(int fd);

void	ft_log_open(char const *file_name);

int		ft_log(char const *format, ...);

void	ft_log_close(void);

#endif
