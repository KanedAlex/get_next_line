/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:25:59 by alienard          #+#    #+#             */
/*   Updated: 2019/11/14 15:56:37 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_fd(t_list *current, t_list **begin)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*foll;

	prev = *begin;
	while (prev && prev->next && prev->currfd != current->currfd
		&& prev->next->currfd != current->currfd)
		prev = prev->next;
	tmp = prev->next;
	if (prev == *begin)
	{
		*begin = tmp;
		free(current);
		return ;
	}
	foll = tmp->next;
	prev->next = foll;
	free(current);
}

t_list	*ft_find_fd(int fd, t_list **begin)
{
	t_list	*tmp;

	tmp = *begin;
	while (tmp && tmp->next && tmp->currfd != fd)
		tmp = tmp->next;
	if (!tmp || tmp->currfd != fd)
	{
		if (!(tmp = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		tmp->rest = NULL;
		tmp->currfd = fd;
		tmp->ret = 0;
		tmp->next = *begin;
		*begin = tmp;
	}
	return (tmp);
}

int		ft_ifnl(char **line, t_list *current, size_t i, char *tmp)
{
	char	*tmprest;
	size_t	j;
	size_t	len;

	j = -1;
	if (!(len = ft_strlen(current->rest))
		|| !(tmp = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	while (++j < i && current->rest[j])
		tmp[j] = current->rest[j];
	tmp[j] = '\0';
	current->rest[j] == '\n' ? j++ : 0;
	if (len < j)
		j = len;
	if (!(tmprest = (char *)malloc(sizeof(char) * (len - j + 1))))
		return (-1);
	i = 0;
	while (current->rest[j])
		tmprest[i++] = current->rest[j++];
	tmprest[i] = '\0';
	free(current->rest);
	current->rest = tmprest;
	*line = tmp;
	return (1);
}

int		ft_check_ln(char **line, t_list *current, char *buffer, t_list **begin)
{
	size_t	i;
	char	*tmp;

	i = -1;
	tmp = *line;
	if (!(current->rest = ft_strjoin_free(current->rest, buffer)))
		return (-1);
	while (current->rest[++i])
	{
		if (current->rest[i] == '\n')
		{
			if ((ft_ifnl(line, current, i, tmp)) == 1)
				return (1);
			return (-1);
		}
	}
	if (current->ret == 0)
	{
		*line = ft_strdup_free(current->rest);
		ft_free_fd(current, begin);
		return (0);
	}
	return (2);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*begin = NULL;
	t_list			*current;
	t_buff			buff;
	int				ret;

	if (fd <= -1 || !line || BUFFER_SIZE == 0
			|| (!(current = ft_find_fd(fd, &begin))))
		return (-1);
	while ((current->ret = read(fd, buff.buffer, BUFFER_SIZE)) > 0)
	{
		if (!(buff.tmp = ft_strdup_buff(buff.buffer, current->ret)))
			return (ft_error(line));
		if ((ret = ft_check_ln(line, current, buff.tmp, &begin)) == 1)
			return (1);
		if (ret != 2)
			return (ret == -1 ? ft_error(line) : 0);
	}
	if (current->ret == -1)
		return (-1);
	if (!(buff.tmp = (char*)malloc(sizeof(char) * 1)))
		return (ft_error(line));
	buff.tmp[0] = '\0';
	if ((ret = ft_check_ln(line, current, buff.tmp, &begin)) == 1)
		return (1);
	return (ret == -1 ? ft_error(line) : 0);
}
