/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:19:32 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 18:44:45 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char const c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static size_t	trim_s(char const *s, char const *set)
{
	size_t	n;

	n = 0;
	while (*s && is_in(*s, set))
	{
		s++;
		n++;
	}
	return (n);
}

static size_t	trim_e(char const *s, char const *set)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = ft_strlen(s) - 1;
	while (i > 0 && is_in(s[i--], set))
		n++;
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		len;
	size_t		start;
	size_t		end;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = trim_s(s1, set);
	if (start == len)
	{
		str = malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		return (str);
	}
	end = trim_e(s1, set);
	(str = malloc(sizeof(char) * (len - start - end + 1)));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + start, len - end - start + 1);
	return (str);
}
