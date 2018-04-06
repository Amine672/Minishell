/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:28:14 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/10 05:19:44 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	d = (char *)malloc(sizeof(*d) * ft_strlen(s) + 1);
	if (d != '\0')
	{
		while (s[i] && *s)
		{
			d[i] = (*f)(s[i]);
			i++;
		}
		d[i] = '\0';
	}
	return (d);
}
