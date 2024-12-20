/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:05:43 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/20 18:59:41 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(long n);
int	ft_printun(unsigned int n);
int	ft_printhex(int nbr, char c);
int	ft_printptr(void *ptr);
int	ft_printf(const char *str, ...);

#endif
