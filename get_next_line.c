/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:31:31 by flfische          #+#    #+#             */
/*   Updated: 2024/03/21 17:59:25 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, save, 0) == -1)
	{
		save[0] = '\0';
		return (NULL);
	}
	bytes_read = 1;
	line = ft_strdup(save);
	if (line == NULL)
		return (NULL);
	while (!ft_strchr(line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, save, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), NULL);
		save[bytes_read] = '\0';
		temp = ft_strjoin(line, save);
		if (temp == NULL)
			return (free(line), NULL);
		free(line);
		line = temp;
	}
	if (line == NULL && bytes_read == 0)
		return (NULL);
	if (ft_strlen(line) == 0 && bytes_read == 0)
		return (free(line), NULL);
	if (line)
	{
		temp = ft_get_line(line);
		free(line);
		line = temp;
	}
	ft_reset_save(save);
	return (line);
}

char	*ft_get_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		line = ft_substr(str, 0, i + 1);
	else
		line = ft_strdup(str);
	return (line);
}

int	ft_reset_save(char *save)
{
	int	i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
	{
		ft_memcpy(save, ft_strchr(save, '\n') + 1, ft_strlen(ft_strchr(save,
					'\n')));
		return (1);
	}
	return (0);
}
