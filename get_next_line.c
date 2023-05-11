/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxipeti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:23:49 by maxipeti          #+#    #+#             */
/*   Updated: 2023/05/11 19:50:00 by maxipeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(stash), stash = NULL, NULL);
	read_add_stash(fd, &stash);
	line = stash_to_line(stash);
	stash = free_stash(stash);
	if (!line || !line[0])
		return (NULL);
	return (line);
}

char	*read_add_stash(int fd, char **stash)
{
	char	*buf;
	ssize_t	ret_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	ret_read = 1;
	while ((ret_read > 0) && (ft_strchr(*stash, '\n') == 0))
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		buf[ret_read] = 0;
		if (ret_read < 0)
		{
			free(buf);
			return (NULL);
		}
		if (ret_read == 0)
			break ;
		if (*stash == NULL)
			*stash = ft_strdup(buf);
		else
			*stash = ft_strjoin(*stash, buf);
	}
	free(buf);
	return (*stash);
}

char	*stash_to_line(char *stash)
{
	char	*temp;
	int		i;

	if (!stash)
		return (NULL);
	temp = malloc(sizeof (char) * (find_n(stash) + 2));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		temp[i] = stash[i];
		i++;
	}
	temp[i] = '\0';
	if (stash[i] == '\n')
		temp[i] = '\n';
	temp[i + 1] = '\0';
	return (temp);
}

char	*free_stash(char *stash)
{
	int		i;
	int		j;
	char	*newstash;

	i = 0;
	newstash = malloc(sizeof (char) * (after_n(stash)+ 1));
	if (newstash == NULL)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		i++;
	}	
	if (stash[i] == '\0')
		return (NULL);
	i++;
	j = 0;
	while (stash[i + j] != '\0')
	{
		newstash[j] = stash[i + j];
		j++;
	}
	newstash[j] = '\0';
	free (stash);
	return (newstash);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	if (s && s[i] == c)
		return (1);
	return (0);
}
