/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:45:31 by jinkim2           #+#    #+#             */
/*   Updated: 2022/03/11 13:46:12 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('Z' >= c && c >= 'A')
		c += 32;
	return (c);
}