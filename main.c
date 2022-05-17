/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:48:36 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/17 12:48:40 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	char *sr;
	
	int fd = open("./41_no_nl", O_RDONLY);
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
