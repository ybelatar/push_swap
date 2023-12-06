/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:14:51 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 00:22:32 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
		}
		else
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

static char	*get_next_word(char const *str, int *ptr, char c)
{
	int		i;
	int		len_word;
	char	*word;

	i = 0;
	len_word = 0;
	while (str[*ptr] && str[*ptr] == c)
		*ptr = *ptr + 1;
	if (!str[*ptr])
		return (NULL);
	while (str[*ptr + len_word] && str[*ptr + len_word] != c)
		len_word++;
	word = malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[*ptr];
		i++;
		*ptr = *ptr + 1;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**words;

	if (!s)
		return (NULL);
	i = 1;
	j = 0;
	count = count_words(s, c);
	words = malloc((count + 2) * sizeof(char *));
	words[0] = "PLACEHOLDER";
	if (!words)
		return (NULL);
	while (i < count + 1)
	{
		words[i] = get_next_word(s, &j, c);
		if (!words[i])
			return (NULL);
		i++;
	}
	words[i] = 0;
	return (words);
}
