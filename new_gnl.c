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

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

char	*ft_read(char **str, int fd)
{
	char	*ligne;
	int	verif;

	ligne = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ligne)
		return (0);
	verif = read(fd, ligne, BUFFER_SIZE);
	if (verif == -1)
		return (0);
	*str = ft_strjoin(*str, ligne);
	return (get_next_line(fd));
}

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

int	ft_strstr(const char *str)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (i);
	i++;
	}
	return (-1);
}

char	*ft_strncpy(char *str, int n)
{
	char	*s;
	int		i;

	if (!str)
		return (0);
	s = malloc(sizeof(char) * (n + 1));
	if (!s)
		return (0);
	i = 0;
	while (str[i] && (i < n))
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	free(str);
	return (s);
}

char	*ft_strdup(char *src)
{
	char	*new_str;
	int	i;

	if (!src)
		return (0);
	new_str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (new_str == 0)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = 0;
	free(src);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	if (start > ft_strlen(s) || len == 0)
		return (0);
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	i = 0;
	while (s[start] && len > 0)
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;
	int		taille;

	taille = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(sizeof(char) * (taille + 1));
	if (final == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		final[i++] = s2[j++];
	final[i] = 0;
	free(s1);
	free(s2);
	return (final);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ligne;
	char		*temp;

	if (ft_strstr(str) != -1)
	{
		temp = ft_substr(str, ft_strstr(str) + 1, ft_strlen(str) - ft_strstr(str) - 1); //la fin de str
		ligne = ft_strncpy(str, ft_strstr(str) + 1); //le debut de str
		str = ft_strdup(temp);
		return (ligne);
	}
	return (ft_read(&str, fd));
}




#include <fcntl.h>

int main()
{
	char *sr;
	
	int fd = open("./get_next_line.h", O_RDONLY);
	sr = get_next_line(fd);
	printf("ligne 1 :%s", sr);
	free(sr);
	sr = get_next_line(fd);
	printf("ligne 2 :%p", sr);
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
}
