/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:50:52 by lpicciri          #+#    #+#             */
/*   Updated: 2023/02/02 15:59:10 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_control(char *str, va_list args, size_t i);
int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(long long nb);
int		ft_putnbr_base(long long n, char *base);
int		check_base(char *base);
int		ft_convertion_ptr(void *p);
int		ft_countnbr(long long nb, char *base);
int		ft_strlen(const char *s);
int		ft_bonus(char *str, size_t i);
int		ft_hashtag_flag(char *str, size_t i);
int		ft_space_flag(char *str, size_t i);
int		ft_bonus(char *str, size_t i);
int		ft_hashtag_flag(char *str, size_t i);
int		ft_space_flag(char *str, size_t i);
#endif
