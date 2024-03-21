/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:31:31 by flfische          #+#    #+#             */
/*   Updated: 2024/03/21 14:56:32 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	save[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	char		*remaining;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, save, 0) == -1)
		return (NULL);
	bytes_read = 1;
	line = ft_get_line(save);
	while (ft_strchr(save, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, save, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), NULL);
		save[bytes_read] = '\0';
		temp = ft_strjoin(line, save);
		free(line);
		line = temp;
	}
	remaining = ft_strchr(save, '\n');
	if (remaining != NULL)
	{
		temp = ft_strdup(remaining + 1);
		ft_strlcpy(save, temp, ft_strlen(temp) + 1);
		free(temp);
	}
	else
		save[0] = '\0';
	if (line == NULL && bytes_read == 0)
		return (NULL);
	if (ft_strchr(save, '\n') != NULL)
		ft_memcpy(save, ft_strchr(save, '\n') + 1, ft_strlen(ft_strchr(save,
					'\n')));
	else
		save[0] = '\0';
	return (line);
}

char	*ft_get_line(char *save)
{
	char	*line;
	size_t	i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, save, i + 1);
	return (line);
}
