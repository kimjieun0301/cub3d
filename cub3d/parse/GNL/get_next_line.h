/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyoo <seokjyoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:37:31 by seokjyoo          #+#    #+#             */
/*   Updated: 2023/04/28 16:35:24 by seokjyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 5

# include <stdlib.h>
# include <unistd.h>
# include "../../LIBFT/libft.h"

char	*get_next_line(int fd);
char	*alloc_line(int fd, char *backup, char *line);
void	backup_maker(char *buffer, char **backup);
char	*re_allocate(char *buffer, char *line);

#endif
