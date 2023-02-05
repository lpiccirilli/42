/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:41:33 by lpicciri          #+#    #+#             */
/*   Updated: 2023/02/03 08:58:40 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_bonus(char *str, size_t i)
{
	int	counter;

	counter = 0;
	if (str[i] == '#')
		counter += ft_hashtag_flag(str, i + 1);
	if (str[i] == ' ')
		counter += ft_space_flag(str, i + 1);
	return (counter);
}

int	ft_hashtag_flag(char *str, size_t i)
{
	if (str[i] == 'x')
	{
		write(1, "0x", 2);
		return (2);
	}
	else if (str[i] == 'X')
	{
		write(1, "0X", 2);
		return (2);
	}
	return (0);
}

int	ft_space_flag(char *str, size_t i)
{
	if (str[i] != '+' && str[i] != 'x' && str[i] != 'X')
	{
		write (1, " ", 1);
		return (1);
	}
	return (0);
}
