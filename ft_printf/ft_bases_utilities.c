/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bases_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:39:26 by lpicciri          #+#    #+#             */
/*   Updated: 2026/07/25 21:55:42 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (!base || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int			size_base;
	int			*nbr_final;
	int			i;
	long long	n;

	i = 0;
	n = nbr;
	nbr_final = (int *) malloc(sizeof(int));
	if (!nbr_final)
		return (0);
	size_base = 0;
	if (check_base(base))
	{
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i++] = nbr % size_base;
			nbr = nbr / size_base;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
	free(nbr_final);
	return (ft_countnbr(n, base));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	return (i);
}
