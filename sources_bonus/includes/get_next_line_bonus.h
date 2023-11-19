/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:54:22 by roglopes          #+#    #+#             */
/*   Updated: 2023/10/01 19:05:33 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/**
 * @brief Reads a line from a file descriptor
 *
 * @param fd File descriptor to read.
 * @return Return a string including \\n if is a line. In case of the file
 * dont have \\n return a string without \\n, NULL if the file is empty
 * or error occurred.
 */
char	*get_next_line(int fd);

/**
 * @brief Calculates the length of the string pointed to by 'argument',
 * before the terminating null byte ('\0') can be found.
 * 
 * @param argument as a true C string, terminated by '\0'
 * @return The number of chars in the string.
*/
size_t	ft_strlen(const char *argument);

/**
 * @brief Duplicate the contents of string 's'. Memory for the
 * new string is obtained with malloc.
 * 
 * @param s a string
 * @return char * a pointer to the duplicate string.
 * It returns NULL if insufficient memory was available.
*/
char	*ft_strdup(const char *s);

/**
 * @brief Allocates (with malloc(3)) and returns a substring
 * from the string 's'. The substring begins at index 'start'
 * and is of maximum size 'len'.
 * 
 * @param s the string from which to create the substring
 * @param start the start index of the substring in the string 's'
 * @param len the maximum length of the substring
 * @return The substring. NULL if the allocation fails.
*/
char	*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Looks for the first occurrence of the character 'c'
 * in the string 's'.
 * 
 * @param s a string
 * @param c a char to be searched for in 's'
 * @return A pointer to the matched character or NULL if the 
 * character is not found. The terminating null byte is considered 
 * part of the string.
*/
char	*ft_strchr(const char *s, int c);

/**
 * @brief Allocates (with malloc(3)) and returns a new string,
 * which is the result of the concatenation of 's1' and 's2'.
 * 
 * @param s1 the prefix string
 * @param s2 the suffix string
 * @return The new string. NULL if the allocation fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);

#endif