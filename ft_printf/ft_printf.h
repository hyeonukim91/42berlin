/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:05:43 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/16 12:37:23 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(char c, int *val);
int	ft_printstr(char *str, int *val);
int	ft_printnbr(long n, int *val);
int	ft_printun(unsigned int n, int *val);
int	ft_printhexu(int n, int *val);
int	ft_printhexl(int n, int *val);
int	ft_printptr(void *ptr, int *val);
int	ft_printf(const char *str, ...);

#endif
