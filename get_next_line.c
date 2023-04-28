/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxipeti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:23:49 by maxipeti          #+#    #+#             */
/*   Updated: 2023/04/27 19:39:55 by maxipeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if(fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	read_add_stash(fd, stash)
	
	stash = ft_substr(stash, '\n',  
}

char	read_add_stash(int fd, char *stash)
{
	char	*temp;
	char	*buf
		
	buf = malloc(sizeof (char) * BUFFER_SIZE + 1);
	while(ft_strchr(buf, '\n'))
	{
		read(fd, buf, BUFFER_SIZE);
		if(stash == NULL)
			stash = ft_strdup(buf);
		else
			temp = ft_strjoin(stash, buf);
	}
	return (temp);
}
