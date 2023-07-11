/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:23:13 by lpicciri          #+#    #+#             */
/*   Updated: 2023/07/11 16:59:58 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

char *first_word(char *str)
{
    int i;
    char *word;
    
    i = 0;
    while (*str == ' ' || *str == '\t')
        str++;
    if (ft_isalpha(*str) == 1)
    {
        while (*str != ' ' && *str != '\t' && *str != '\0')
        {
            i++;
            str++;
        } 
    }
    str = str -  i;
    word = (char *)malloc((sizeof(char) * i) + 1);
    i = 0;
    while (ft_isalpha(*(str + i)) == 1)
    {
        *(word + i) = *(str + i);
        i++;        
    }
    return (word);
}

void first_word_check(char * word)
{
    if (access(word, F_OK) == 0)
        printf("COMANDO TROVATO\n");
    else if (access(word, F_OK) == -1)
        printf("COMANDO NON TROVATO\n");
}

int main(int ac, char **av, char **envp)
{

    (void)ac;
    (void)envp;
    printf("%s\n", first_word(av[1]));
    first_word_check(first_word(av[1]));
}
