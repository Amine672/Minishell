/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 06:12:01 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/12 19:33:40 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**count_word(const char *str, char c)
{
	int		i;
	int		word;
	char	**tab;

	i = 0;
	word = 0;
	if (!str[0])
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (!word && !str[i])
			return (NULL);
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
		word++;
	}
	tab = (char **)ft_memalloc(sizeof(char *) * (word + 1));
	tab[word] = 0;
	return (tab);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		i;
	int		u;
	int		t;

	if (str == NULL)
		return (NULL);
	if ((tab = count_word(str, c)) == NULL)
		return (NULL);
	i = 0;
	t = -1;
	while (str[i])
	{
		u = 0;
		while (str[i] && str[i] == c)
			i++;
		while (str[i + u] && str[i + u] != c)
			u++;
		tab[++t] = ft_strsub(str, i, u);
		i += u;
		while (str[i] && str[i] == c)
			i++;
	}
	return (tab);
}
