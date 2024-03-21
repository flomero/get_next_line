/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:31:05 by flfische          #+#    #+#             */
/*   Updated: 2024/03/21 18:38:59 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*cs;
	unsigned char	uc;

	cs = (unsigned char *)s;
	uc = (unsigned char)c;
	while (*cs != '\0')
	{
		if (*cs == uc)
			return ((char *)cs);
		cs++;
	}
	if (uc == '\0')
		return ((char *)cs);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	i = 0;
	if (dst == NULL && src == NULL && n)
		return (NULL);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (i < n)
	{
		*cdst = *csrc;
		cdst++;
		csrc++;
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dest = (char *)malloc(len);
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_memcpy(dest, s1, len - 1);
	dest[len - 1] = '\0';
	return (dest);
}
