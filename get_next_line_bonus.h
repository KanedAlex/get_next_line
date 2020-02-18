/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:11:38 by alienard          #+#    #+#             */
/*   Updated: 2019/11/14 21:08:25 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				currfd;
	int				ret;
	char			*rest;
	struct s_list	*next;
}				t_list;

typedef struct	s_buff
{
	char			buffer[BUFFER_SIZE];
	char			*tmp;
}				t_buff;

int				get_next_line(int fd, char **line);
int				ft_check_ln(char **line, t_list *current,
				char *buffer, t_list **begin);
int				ft_ifnl(char **line, t_list *current, size_t i, char *tmp);
char			*ft_strdup_buff(char *buffer, int ret);
void			ft_free_fd(t_list *current, t_list **begin);
void			ft_find_fd(int fd, t_list **begin, t_list **current);
size_t			ft_strlen(char *str);
char			*ft_strdup_free(char *s1);
char			*ft_strjoin_free(char *s1, char *s2);
int				ft_error(char **line);

#endif
