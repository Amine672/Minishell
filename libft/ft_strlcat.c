/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:38:21 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/09 04:21:41 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;
	size_t q;

	q = 0;
	i = ft_strnlen(dst, size);
	len = i;
	while (src[q] && i < size - 1)
	{
		dst[i] = src[q];
		i++;
		q++;
	}
	if (len < size)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
