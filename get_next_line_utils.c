/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxipeti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:07:48 by maxipeti          #+#    #+#             */
/*   Updated: 2023/04/28 09:25:46 by maxipeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*stash_to_line(char *stash, char c)
{
	char	*temp;
	int	i;
	if(!stash)
		return(NULL);
	temp = malloc(sizeof (char) * ft_strlen(stash + 1)
	i = 0;
	while(stash[i] != c)
	{
		temp[i] = stash[i];
		i++;
	}
	temp[i] = "\n";
	return(temp);
}

char	*free_stash_befor(char *stash, char c)
{
	char temp;
}
