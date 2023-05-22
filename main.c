/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:10:34 by arincon           #+#    #+#             */
/*   Updated: 2023/05/22 16:06:08 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test/text.txt", O_RDONLY);
	//fd = open("test/text2.txt", O_RDONLY);
	//fd = open("test/text3_no_nl.txt", O_RDONLY);
	if (fd == -1 || fd > 1024)
	{
		printf("FILE DESCRIPTOR ERROR\n");
		return (1);
	}
	line = get_next_line(fd);
	printf("line 1: #%s#\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 2: #%s#\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 3: #%s#\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 4: #%s#\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 5: #%s#\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 6: #%s#\n", line);
	free(line);
	line = get_next_line(fd);
	printf("line 7: #%s#\n", line);
	free(line);
	return (0);
}


/* int main(void)
{
	char *str;
	// int fd;

	// fd = open("z.c", O_RDONLY);
	str = get_next_line(0);
	while(str)
	{
		printf("str=%s]\n", str);
		free(str);
		str = get_next_line(0);
	}
	return (0);
} */
