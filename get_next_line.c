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

//regarde str[i] ca rend tout le reste sinon

char	*get_next_line(int fd)
{
	static char	*str;
	int			i;
	char		*ligne;
	int			verif;
	char		*temp;

	ligne = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ligne)
		return (0);
	verif = read(fd, ligne, BUFFER_SIZE);
	ligne[verif] = 0;
	if (verif == -1)
		return (0);
	if (!str)
		str = ft_strdup("");
	if (verif == BUFFER_SIZE)
	{
		i = 0;
		while (ligne[i] && ligne[i] != '\n')
			i++;
		if (i == verif)
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
			str = ft_strdup(ligne + i + 1);
			return (ft_strjoin(temp, ft_strncpy(ligne, i + 1)));
		}
	}
	else
	{
		i = 0;
		while (ligne[i] && ligne[i] != '\n')
			i++;
		if (i == verif)
		{
			temp = ft_strdup(str);
			return (ft_strjoin(temp, ligne));
		}
		else
		{
			temp = ft_strdup(str);
			free(str);
			str = ft_strdup(ligne + i + 1);
			return (ft_strjoin(temp, ft_strncpy(ligne, i + 1)));
		}
	}
}

#include <fcntl.h>

int main()
{
	char *sr;
	
	int fd = open("./get_next_line.h", O_RDONLY);
	sr = get_next_line(fd);
	printf("ligne 1 :%s", sr);
	sr = get_next_line(fd);
	printf("ligne 2 :%s", sr);
	sr = get_next_line(fd);
	printf("ligne 3 :%s", sr);
	sr = get_next_line(fd);
	printf("ligne 4 :%s", sr);
	sr = get_next_line(fd);
	printf("ligne 5 :%s", sr);
	close(fd);
}
