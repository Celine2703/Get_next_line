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

void	*ft_calloc(size_t size, size_t espace)
{
	void		*tab;
	size_t		cpt;
	size_t		taille;

	taille = espace * size;
	if (size == 0 || espace == 0)
		return (0);
	if (taille / size != espace)
		return (0);
	cpt = 0;
	tab = malloc(taille);
	if (tab == 0)
		return (0);
	while (cpt < taille)
	{
		((char *)tab)[cpt] = 0;
		cpt ++;
	}
	return (tab);
}

char	*ft_reste(char **str, char *ligne, int indic)
{
	int		i;
	char	*temp;

	if (!(*str) || (*str)[0] == 0)
	{
		if (ligne[0] == 0)
		{
			free(ligne);
			return (0);
		}
		return (ligne);
	}
	if (indic == 1)
		return (ft_strjoin(*str, ligne));
	i = 0;
	*str = ft_strjoin(*str, ligne);
	while ((*str)[i] != 0 && (*str)[i] != '\n')
		i++;
	temp = ft_strdup(*str);
	free(*str);
	*str = ft_strdup(temp + i + 1);
	if ((*str)[0] == 0)
	{
		free(*str);
		*str = 0;
	}
	return (ft_strncpy(temp, i + 1));
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ligne;
	int			verif;
	int			i;

	ligne = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!ligne)
		return (0);
	verif = read(fd, ligne, BUFFER_SIZE);
	if (verif == -1)
	{
		free(ligne);
		return (0);
	}
	if (verif != BUFFER_SIZE)
		return (ft_reste(&str, ligne, 1));
	if (!str)
		str = ft_calloc(sizeof(char), 1);
	i = 0;
	while (ligne[i] && ligne[i] != '\n')
		i++;
	if (verif == i && ligne[i] != '\n')
	{
		str = ft_strjoin(str, ligne);
		return (get_next_line(fd));
	}
	return (ft_reste(&str, ligne, 0));
}
