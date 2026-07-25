/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:53:23 by lpicciri          #+#    #+#             */
/*   Updated: 2026/07/25 18:39:29 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_reads(int fd, char *str, char *newline);
char		*ft_strchr(const char *str, int c);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
#endif
