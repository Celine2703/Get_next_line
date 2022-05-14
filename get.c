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
	static char	str[BUFFER_SIZE + 1];
	char		*ligne;
	int			verif;
	int			i;

	verif = read(fd, str, BUFFER_SIZE);
	if (verif == -1)
		return (0);
	str[verif] = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	temp = ft_substr(str, i + 1, ft_strlen(str) - (i + 1));
	free(str);
	
	ligne = strncpy(str, i + 1);
	return (ligne);
}
