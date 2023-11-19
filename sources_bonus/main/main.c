/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:27:31 by roglopes          #+#    #+#             */
/*   Updated: 2023/10/01 19:05:21 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);

static int	ft_atoi(const char *nptr)
{
	int	number;
	int	signal;
	int	i;

	number = 0;
	signal = 1;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			signal *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (nptr[i] - '0') + (number * 10);
		i++;
	}
	return (number * signal);
}

static size_t	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		fd_two;
	int		index;
	char	*gnl;

	if (argc >= 1 && argc <= 3)
		return (write(1, "File name missing.\n", \
		ft_strlen("File name missing.\n")));
	if (argc > 4)
		return (write(1, "Too many arguments.\n", \
		ft_strlen("Too many arguments.\n")));
	fd = open(argv[1], O_RDONLY);
	fd_two = open(argv[2], O_RDONLY);
	index = ft_atoi(argv[3]);
	if (index < 0)
		return (write(1, "Input a number positivi.\n", \
		ft_strlen("Input a number positivi.\n")));
	while (index--)
	{
		gnl = get_next_line(fd);
		if (gnl)
			write(1, gnl, ft_strlen(gnl));
		free(gnl);
		gnl = get_next_line(fd_two);
		if (gnl)
			write(1, gnl, ft_strlen(gnl));
		free(gnl);
	}
	close(fd);
	return (0);
}
