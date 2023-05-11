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

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;
//	char	*temp;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = read_add_stash(fd, stash);
	line =stash_to_line(stash);
	stash=free_stash(stash);
	return(line);	
}

char	*read_add_stash(int fd, char *stash)
{
	//char	*temp;
	char	*buf;
	
	buf = malloc(sizeof (char) * BUFFER_SIZE + 1);
	if(buf == NULL)
		return(NULL);
	while(!ft_strchr(buf, '\n') || !ft_strchr(buf, '\0'))
	{
		read(fd, buf, BUFFER_SIZE);
		if(stash == NULL)
			stash = ft_strdup(buf);
		else
			stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char    *stash_to_line(char *stash)
{
        char    *temp;
        int     i;
        if(!stash)
                return(NULL);
        temp = malloc(sizeof (char) * (find_n(stash) + 1));
	if(temp == NULL)
		return(NULL);
        i = 0;
	if(stash[0] == '\n')
	{
		temp[0] = stash[0];
		i++;
		temp[i]= '\0';
		return (temp);
	}
	while(stash[i] != '\n' && stash[i])
        {
                temp[i] = stash[i];
                i++;
        }
	temp[i] = '\0';
	stash = stash + i;
	//free(stash);
        return(temp);
}

char	*free_stash(char *stash)
{
	int	i;
	int	j;
	char	*newstash;
	
	i = 0;
	newstash = malloc(sizeof (char) * (after_n(stash)+ 1));
	if(newstash == NULL)
		return(NULL);
	while(stash[i] != '\n' && stash[i] !='\0')
	{
		i++;
	}	
	//i++;
	if (stash[i] == '\0')
	{
		return(NULL);
	}
	i++;
	j = 0;
	while(stash[i + j] != '\0')
		{	
			newstash[j] = stash[i + j];
			j++;
		}
		newstash[j] = '\0';
	free(stash);
	return(newstash);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char) c)
	{
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)s + i);
	return (NULL);
}
