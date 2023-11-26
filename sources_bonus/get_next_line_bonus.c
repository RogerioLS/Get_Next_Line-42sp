/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:54:12 by roglopes          #+#    #+#             */
/*   Updated: 2023/11/26 18:04:40 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line_bonus.h"

static void	ft_free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*ft_extract_line(char **read_line)
{
	char	*line;
	char	*t_free;
	int		i;

	i = 0;
	while ((*read_line)[i] != '\0' && (*read_line)[i] != '\n')
		i++;
	t_free = *read_line;
	line = ft_substr(t_free, 0, i + 1);
	*read_line = ft_strdup(&(*read_line)[i + 1]);
	ft_free_ptr(&t_free);
	return (line);
}

static int	ft_read_file(int fd, char **buffer, char **read_line)
{
	char	*t_free;
	int		buffer_read;

	buffer_read = 1;
	while (!ft_strchr(*read_line, '\n') && buffer_read)
	{
		buffer_read = read(fd, *buffer, BUFFER_SIZE);
		if (buffer_read == -1)
			return (buffer_read);
		(*buffer)[buffer_read] = '\0';
		t_free = *read_line;
		*read_line = ft_strjoin(t_free, *buffer);
		ft_free_ptr(&t_free);
	}
	return (buffer_read);
}

static char	*ft_get_line(int fd, char **buffer, char **read_line)
{
	char	*t_free;
	int		buffer_read;

	if (ft_strchr(*read_line, '\n'))
		return (ft_extract_line(read_line));
	buffer_read = ft_read_file(fd, buffer, read_line);
	if ((buffer_read == 0 && !**read_line) || buffer_read == -1)
	{
		ft_free_ptr(read_line);
		return (NULL);
	}
	if (ft_strchr(*read_line, '\n'))
		return (ft_extract_line(read_line));
	if (!ft_strchr(*read_line, '\n') && **read_line)
	{
		t_free = ft_strdup(*read_line);
		ft_free_ptr(read_line);
		return (t_free);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*read_line[OPEN_MAX];
	char		*buffer;
	char		*print_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (!read_line[fd])
		read_line[fd] = ft_strdup("");
	print_line = ft_get_line(fd, &buffer, &read_line[fd]);
	ft_free_ptr(&buffer);
	return (print_line);
}
