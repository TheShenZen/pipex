/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:36:33 by seciurte          #+#    #+#             */
/*   Updated: 2021/04/01 18:47:23 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_wrds(char const *s, char c)
{
	int	swt;
	int	cnt;

	swt = 0;
	cnt = 0;
	while (s != NULL && *s)
	{
		if (*s == c)
			swt = 0;
		else if (swt == 0)
		{
			swt = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static size_t	wrdlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	l_stc;
	size_t	l_wrd;

	l_stc = cnt_wrds(s, c) + 1;
	str = malloc(sizeof(char **) * l_stc);
	if (str == NULL)
		return (NULL);
	while (s != NULL && *s)
	{
		if (*s != c)
		{
			l_wrd = wrdlen(s, c) + 1;
			*str = malloc(sizeof(char) * l_wrd);
			if (str == NULL)
				return (NULL);
			ft_strlcpy(*str, s, l_wrd);
			s += l_wrd - 1;
			str++;
		}
		else
			s++;
	}
	*str = NULL;
	return (str - l_stc + 1);
}
