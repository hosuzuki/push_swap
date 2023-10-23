/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:53 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/12/23 11:01:59 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../lib/ft_printf/includes/ft_printf.h"

# define BUFFER_SIZE 100
# define HAVE_NEW_LINE 1
# define ERROR -1
# define END 0

// size_t	ft_strlen(const char *s);
// char	*ft_strjoin(const char *s1, const char *s2);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strndup(const char *content, size_t len);
// t_node	*ft_lstnew(int fd, void *content);
char	*get_next_line(int fd);

#endif
