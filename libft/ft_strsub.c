/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 00:57:08 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/10 01:18:45 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *d;

	if (!s)
		return (NULL);
	d = (char *)malloc(sizeof(*d) * (len) + 1);
	if (!d)
		return (NULL);
	d = ft_strncpy(d, &s[start], len);
	d[len] = '\0';
	return (d);
}
