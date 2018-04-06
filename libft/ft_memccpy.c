/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:41:33 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/08 06:58:26 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;
	while (n != '\0')
	{
		if ((*d++ = *s++) == c)
			return (d);
		n--;
	}
	return (NULL);
}
