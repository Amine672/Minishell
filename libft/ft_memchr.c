/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:20:01 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/11 22:59:45 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	c1;

	s = (unsigned char *)src;
	c1 = (unsigned char)c;
	while (n != '\0')
	{
		if (*s != c1)
			s++;
		else
			return (s);
		n--;
	}
	return (NULL);
}
