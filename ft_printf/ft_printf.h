/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:50:52 by lpicciri          #+#    #+#             */
/*   Updated: 2023/02/20 20:25:49 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
void	ft_put_ptr(unsigned long long p);
int		ft_ptrlen(unsigned long long p);
int		ft_strlen(const char *s);
int		ft_printhex(unsigned int hex, const char format);
void	ft_putnbrhex(unsigned int hex, const char format);
int		ft_lenhex(unsigned int nbr);
int		ft_print_ptr(unsigned long long p);
int		ft_printunsigned(unsigned int unsnbr);
int		ft_printnbr(int nbr);
int		ft_putnbr(long int nbr);
#endif
