/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxipeti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:07:48 by maxipeti          #+#    #+#             */
/*   Updated: 2023/05/11 18:55:46 by maxipeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_n(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;
	size_t	i;

	len = ft_strlen(s);
	dest = (char *)malloc(sizeof (char) * (len +1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	dst = malloc(sizeof (char) * (ft_strlen(s1) +ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	after_n(char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\n' && stash[i])
	{
		i++;
	}
	if (stash[i] == '\0')
		return (0);
	while (stash[i + j] != '\0')
	{
		j++;
	}
	return (j);
}

int main(void)
{
    int fd;
    char *line;

    fd = open("maxime.txt", O_RDONLY);
	line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
	line = get_next_line(fd);
    }
    close(fd);
    return 0;
}
