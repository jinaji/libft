/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:02:31 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/25 13:46:15 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	size_t		len;
	int			i;
	int			j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	return (arr);
}
