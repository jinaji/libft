/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:04:32 by jinkim2           #+#    #+#             */
/*   Updated: 2022/04/07 16:27:05 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	word_count(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			cnt++;
			while (str[i] != c && str[i])
				i++;
		}	
		else
			i++;
	}
	return (cnt);
}

static	void	malloc_err(char **arr, int idx)
{
	while (idx--)
		free (arr[idx]);
	free (arr[idx]);
	free (arr);
	arr = 0;
}

static char	*strndup(const char *s1, int i, int j, int len)
{
	int		idx;
	char	*arr;

	idx = 0;
	arr = (char *)malloc((sizeof(char) * len) + 1);
	if (!arr)
		return (0);
	while (i > j)
	{
		arr[idx] = s1[j];
		idx++;
		j++;
	}
	arr[idx] = '\0';
	return (arr);
}

static	char	**fill(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (s[i] && idx < word_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		arr[idx] = strndup(s, i, j, (i - j));
		if (!arr)
		{
			malloc_err(arr, idx);
			return (0);
		}
		idx++;
	}
	arr[idx] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**arr;

	if (!s)
		return (0);
	cnt = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!arr)
		return (0);
	return (fill(arr, s, c));
}
