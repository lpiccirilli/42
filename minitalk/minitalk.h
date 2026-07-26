/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:28 by lpicciri          #+#    #+#             */
/*   Updated: 2026/07/26 19:18:14 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

void	print_pid(pid_t pid);
int		ft_putnbr(long int nbr);
int		ft_putchar(int c);
int		ft_atoi(const char *str);

#endif
