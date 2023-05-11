/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxipeti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:32:53 by maxipeti          #+#    #+#             */
/*   Updated: 2023/05/11 19:49:39 by maxipeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

#endif

char    *get_next_line(int fd);
char    *read_add_stash(int fd, char **stash);
char    *stash_to_line(char *stash);
int     find_n(char *stash);
char    *free_stash(char *stash);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
int     after_n(char *stash);
char    *ft_strdup(const char *s);
int    ft_strchr(char *s, char c);


#endif
