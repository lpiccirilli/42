/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:50:20 by lpicciri          #+#    #+#             */
/*   Updated: 2023/07/11 13:08:03 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

size_t  str_lenght(char *str)
{
    int len;

    len = 0;
    while (*str)
    {
        if (ft_isalpha(*str) == 1)
            len++;
        str++;
    }
    return (len);
}

char *str_split(char *str, int len)
{
    char *str_split;
    int i;

    i = 0;
    str_split = (char *)malloc((sizeof(char) * len) + 1);
    while (*str)
    {
        if (*str != ' ' && *str != '\t')
        {   
            *(str_split + i) = *str;
            i++;
        }
        str++;
    }
    *(str_split + i) = '\0';
    return(str_split);
}

int main(int ac, char **av)
{

    (void)ac;
    int len = str_lenght(av[1]);
    str_split(av[1], len);
    printf("%d\n", len);
    printf("%s\n", str_split(av[1], len));
}
