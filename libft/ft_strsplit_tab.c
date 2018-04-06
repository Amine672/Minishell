/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:37:11 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/12 19:32:29 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				check_error(char c)
{
	char	*str;
	int		i;

	i = -1;
	str = " 	";
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

char			**count_word_tab(const char *str)
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
		while (str[i] && check_error(str[i]))
			i++;
		if (!word && !str[i])
			return (NULL);
		while (str[i] && !(check_error(str[i])))
			i++;
		while (str[i] && check_error(str[i]))
			i++;
		word++;
	}
	tab = (char **)ft_memalloc(sizeof(char *) * (word + 1));
	tab[word] = 0;
	return (tab);
}

char			**ft_strsplit_tab(char const *str)
{
	int		i;
	char	**tab;
	int		u;
	int		t;

	if (str == NULL)
		return (NULL);
	if ((tab = count_word_tab(str)) == NULL)
		return (NULL);
	i = 0;
	t = -1;
	while (str[i])
	{
		u = 0;
		while (str[i] && check_error(str[i]))
			i++;
		while (str[i + u] && !(check_error(str[i + u])))
			u++;
		tab[++t] = ft_strsub(str, i, u);
		i += u;
		while (str[i] && check_error(str[i]))
			i++;
	}
	return (tab);
}
