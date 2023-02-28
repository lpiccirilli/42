/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:49:48 by lpicciri          #+#    #+#             */
/*   Updated: 2023/02/28 17:54:12 by lpicciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_n_line(char *str)
{
	int		i;
	char	*nline;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0' || str[1] == '\0')
		return (NULL);
	nline = ft_substr(str, i + 1, ft_strlen(str) - i);
	if (*nline == '\0')
	{
		free(nline);
		nline = NULL;
	}
	str[i + 1] = '\0';
	return (nline);
}

char	*ft_reads(int fd, char *str, char *newline)
{
	int		ret;
	char	*char_tmp;

	ret = 1;
	while (ret != '\0')
	{
		ret = read(fd, str, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		else if (ret == 0)
			break ;
		str[ret] = '\0';
		if (!newline)
			newline = ft_strdup("");
		char_tmp = newline;
		newline = ft_strjoin(char_tmp, str);
		free(char_tmp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_reads(fd, buf, str);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	str = ft_n_line(line);
	return (line);
}
