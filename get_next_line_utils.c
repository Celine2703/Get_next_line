/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:52:01 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/12 14:52:02 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *str, int n)
{
	char	*s;
	int		i;

	if (!str)
		return (0);
	s = malloc(sizeof(char) * (n + 1));
	if (!)
		return (0);
	i = 0;
	while (str[i] && (i < n))
		s[i] = str[i++];
	free(str);
	return (s);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (new_str == 0)
		return (0);
	ft_strcpy(new_str, src);
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*final;
	int		taille;

	if (!s1)
		return (s2);
	taille = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(sizeof(char) * taille + 1);
	if (final == 0)
		return (0);
	i = 0;
	while (s1[i])
		final[i] = s1[i++];
	j = 0;
	while (s2[j])
		final[i++] = s2[j++];
	final[i] = '\0';
	free(s1);
	free(s2);
	return (final);
}