/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:10:34 by arincon           #+#    #+#             */
/*   Updated: 2023/01/20 18:03:05 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_first_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_calloc (i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' && stash[i])
		line[i] = '\n';
	return (line);
}

static char	*ft_new_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] != '\n' && stash[i])
		i++;
	new_stash = ft_calloc(ft_strlen(stash) - i + 1, 1);
	if (!new_stash)
		return (NULL);
	j = -1;
	while (stash[i])
		new_stash[++j] = stash[++i];
	new_stash[++j] = '\0';
	free(stash);
	return (new_stash);
}

/* static char	*ft_free_strjoin(char *stash, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buf);
	free(stash);
	return (tmp);
} */

char	*ft_read(int fd, char *buf, char *stash)
{
	//char	buf[BUFFER_SIZE + 1];
	int		read_re;
	char	*tmp;

	read_re = 1;
	while (read_re != 0)
	{
		read_re = read(fd, buf, BUFFER_SIZE);
		buf[read_re] = '\0';
		if (!stash)
			stash = ft_calloc(1, 1);
		//stash = ft_free_strjoin(stash, buf);
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*stash;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	stash = ft_read(fd, buf, stash);
	line = ft_first_line(stash);
	stash = ft_new_stash(stash);
	free(buf);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text3_no_nl.txt", O_RDONLY);
	//fd = open("text2.txt", O_RDONLY);
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
} */


int main(void)
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
}
