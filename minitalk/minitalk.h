/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:28 by lpicciri          #+#    #+#             */
/*   Updated: 2023/03/09 15:27:37 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <signal.h>

void	print_pid(pid_t pid);
int		ft_putnbr(long int nbr);
int		ft_putchar(int c);
int		ft_atoi(const char *str);

#endif
