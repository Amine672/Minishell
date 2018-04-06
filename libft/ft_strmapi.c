/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:53:27 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/10 05:19:26 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	j;

	j = 0;
	if (!s || !f)
		return (NULL);
	d = (char *)malloc(sizeof(*d) * ft_strlen(s) + 1);
	if (d != '\0')
	{
		while (s[j] && *s)
		{
			d[j] = (*f)(j, s[j]);
			j++;
		}
		d[j] = '\0';
	}
	return (d);
}
