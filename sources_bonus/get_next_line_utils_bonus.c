/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:54:04 by roglopes          #+#    #+#             */
/*   Updated: 2023/09/02 21:32:36 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *argument)
{
	unsigned int	count;

	count = 0;
	while (argument[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	str_length;
	size_t	i;

	str_length = ft_strlen(s) + 1;
	str = (char *)malloc(str_length * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < str_length)
		str[i] = s[i];
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	length;
	char	*sub_string;

	length = ft_strlen(s);
	count = 0;
	if (s == NULL)
		return (NULL);
	if (start >= length)
		return (ft_strdup(""));
	if (length - start < len)
		len = length - start;
	sub_string = malloc((len + 1) * sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	while (len--)
	{
		sub_string[count] = s[start];
		count++;
		start++;
	}
	sub_string[count] = '\0';
	return (sub_string);
}

char	*ft_strchr(const char *s, int c)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		if (s[length] == (unsigned char) c)
			return ((char *)s + length);
		length++;
	}
	if (s[length] == (unsigned char) c)
		return ((char *)s + length);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_string;
	int		count;
	int		length_string_s1;
	int		length_string_s2;

	length_string_s1 = ft_strlen(s1);
	length_string_s2 = ft_strlen(s2);
	join_string = malloc((length_string_s1 + length_string_s2 + 1));
	if (s1 == NULL || s2 == NULL || join_string == NULL)
		return (NULL);
	count = 0;
	while (s1[count] != '\0')
	{
		join_string[count] = s1[count];
		count++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		join_string[length_string_s1 + count] = s2[count];
		count++;
	}
	join_string[length_string_s1 + length_string_s2] = '\0';
	return (join_string);
}
