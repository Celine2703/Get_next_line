/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:15:25 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/17 14:15:28 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_read(char **str, int fd)
{
	char	*ligne;
	int	verif;

	ligne = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!ligne)
		return (0);
	verif = read(fd, ligne, BUFFER_SIZE);
	if (verif == -1)
	{
		free(ligne);
		free(*str);
		*str = 0;
		return (0);
	}
	if (verif == 0)
	{
		free(ligne);
		return (ft_strdup(*str));
	}
	*str = ft_strjoin(*str, ligne);
	return (get_next_line(fd));
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ligne;
	char		*temp;

	if (str && ft_strstr(str) != -1)
	{
		temp = ft_substr(str, ft_strstr(str) + 1, ft_strlen(str) - ft_strstr(str) - 1); //la fin de str
		ligne = ft_strncpy(str, ft_strstr(str) + 1); //le debut de str
		str = ft_strdup(temp);
		return (ligne);
	}
	else
	{
		ligne = ft_read(&str, fd);
		if (!(str[0]))
			str = 0;
	}
	return (ligne);
}



/*
#include <fcntl.h>

int main()
{
	char *sr;
	
	int fd = open("./41_with_nl", O_RDONLY);
	sr = get_next_line(fd);
	printf("ligne 1 :%s", sr);
	free(sr);
	sr = get_next_line(fd);
	printf("ligne 2 :%s", sr);
	free(sr);
	sr = get_next_line(fd);
	printf("ligne 3 :%s", sr);
	free(sr);
	sr = get_next_line(fd);
	printf("ligne 4 :%s", sr);
	free(sr);
	sr = get_next_line(fd);
	printf("ligne 5 :%s", sr);
	free(sr);
	sr = get_next_line(fd);
	printf("ligne 6 :%s", sr);
	free(sr);
	sr = get_next_line(fd);
	printf("ligne 7 :%s", sr);
	free(sr);
	close(fd);
}*/
