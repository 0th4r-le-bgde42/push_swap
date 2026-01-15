/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschappe <mschappe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:37:57 by mschappe          #+#    #+#             */
/*   Updated: 2026/01/14 13:15:11 by mschappe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_count_word(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			words++;
		s++;
	}
	return (words);
}

static	char	*ft_get_word(const char *s, int index)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((index + 2) * sizeof(char));
	if (!word)
		return (0);
	while (i <= index)
	{
		word[i] = *(s - index + i);
		i++;
	}
	word[i] = '\0';
	return (word);
}

static	void	ft_free(char **res, int i)
{
	while (i >= 0)
	{
		if (res[i] != NULL)
		{
			free(res[i]);
			res[i] = NULL;
		}
		i--;
	}
	free(res);
}

static	int	ft_set_res(char const *s, char c, char **res)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			res[i] = ft_get_word(s, index);
			if (!res[i])
			{
				ft_free(res, i - 1);
				return (1);
			}
			i++;
		}
		if (*s == c || *s == '\0')
			index = 0;
		else
			index++;
		s++;
	}
	res[i] = NULL;
	return (0);
}

char	**ft_split(char *s, char c, t_tracking **track)
{
	char	**res;

	if (!s)
		ft_error(track);
	res = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!res)
		ft_error(track);
	if (ft_set_res(s, c, res) == 1)
	{
		free(s);
		ft_error(track);
	}
	free(s);
	return (res);
}
