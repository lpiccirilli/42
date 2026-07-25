/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:50:52 by lpicciri          #+#    #+#             */
/*   Updated: 2026/07/25 22:12:06 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(char *s);
void	ft_put_ptr(unsigned long long p);
int		ft_ptrlen(unsigned long long p);
int		ft_printhex(unsigned int hex, const char format);
void	ft_putnbrhex(unsigned int hex, const char format);
int		ft_lenhex(unsigned int nbr);
int		ft_print_ptr(unsigned long long p);
int		ft_printunsigned(unsigned int unsnbr);
int		ft_printnbr(int nbr);
int		ft_putnbr(long long nb);
int		ft_putnbr_base(long long nbr, char *base);
int		ft_countnbr(long long nb, char *base);
int		ft_putchar(int c);
size_t	ft_strlen(const char *s);

#endif
