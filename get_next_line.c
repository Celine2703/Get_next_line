/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:51:43 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/12 14:51:44 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	int		i;
	char		*ligne;
	int		verif;
	char		*temp;

	ligne = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ligne)
		return (0);
	verif = read(fd, ligne, BUFFER_SIZE);
	if (verif == -1)
		return (0);
	ligne[verif + 1] = 0;
	else if (verif == BUFFER_SIZE)
	{
		i = 0;
		while (ligne[i] && ligne[i] != '\n')
			i++;
		if (i == verif - 1)
		{
			temp = ft_strdup(str);
			free(str);
			str = ft_strjoin(temp, ligne);
			return (get_next_line(fd));
		}
		else
		{
			temp = ft_strdup(str);
			free(str);
			str = ft_strdup(ligne + i);
			return (ft_strjoin(ft_strncpy(ligne, i), temp));
		}
	}
	else     //verif < BS
		i = 0;
		while (ligne[i] && ligne[i] != '\n')
			i++;
		if (i == verif - 1)
			return (ft_strjoin(str, ligne));
		else
		{
			temp = ft_strdup(str);
			free(str);
			str = ft_strdup(ligne + i);
			return (ft_strjoin(ft_strncpy(ligne, i), temp));
		}
}
