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
#include <stdio.h>

int	ft_strchr(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			i;
	char		*ligne;
	int			verif;
	char		*temp;

	if (ft_strchr(str))
	{
		temp = ft_strncpy(str, ft_strchr(str) + 1);
		ligne = malloc(sizeof(char) * (ft_strchr(str) + 1));
		i = ft_strchr(str) + 1;
		verif = 0;
		while (str[i])
		{
			ligne[verif] = str[i];
			i++;
			verif++;
		}
		ligne[verif] = 0;
		free(str);
		str = ft_strdup(ligne);
		free(ligne);
		return (temp);
	}
	ligne = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ligne)
		return (0);
	verif = read(fd, ligne, BUFFER_SIZE);
	ligne[verif] = 0;
	if (verif == -1)
		return (0);
	if (!str)
		str = ft_strdup("");
	if (verif == BUFFER_SIZE) //si on a pas fini le fichier
	{
		i = 0;
		while (ligne[i] && ligne[i] != '\n')
			i++;
		if (i == verif) //si on a pas fini la ligne
		{
			temp = ft_strdup(str);
			free(str);
			str = ft_strjoin(temp, ligne);
			return (get_next_line(fd));
		}
		else //si on a trouve au moins une ligne
		{
			temp = ft_strdup(str);
			free(str);
			str = ft_strdup(ligne + i + 1);
			//printf("le reste est de : %s\n\n", str);
			return (ft_strjoin(temp, ft_strncpy(ligne, i + 1)));
		}
	}
	else //si on a fini le fichier
	{
		i = 0;
		while (ligne[i] && ligne[i] != '\n')
			i++;
		if (i == verif) //si on a pas trouve de ligne
		{
			temp = ft_strdup(str);
			return (ft_strjoin(temp, ligne));
		}
		else //si on a trouve une ligne
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
	sr = get_next_line(fd);
	printf("ligne 6 :%s", sr);
	sr = get_next_line(fd);
	printf("ligne 7 :%s", sr);
	close(fd);
}
