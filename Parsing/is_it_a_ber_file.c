/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_a_ber_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:47:03 by vsozonof          #+#    #+#             */
/*   Updated: 2023/10/18 14:18:38 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_it_a_ber_file(char **argv)
{
	unsigned int	i;
	char			*set;

	set = "ber";
	i = 0;
	while (argv[1][i])
	{
		if (i == (ft_strlen(argv[1]) - 4) && argv[1][i] != '.')
			return (0);
		if (argv[1][i] == '.')
		{
			if (i == (ft_strlen(argv[1]) - 4))
			{
				i++;
				if (!(extension_checker(set, i, argv)))
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	extension_checker(char *set, int len_start, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][len_start] && set[i])
	{
		if (argv[1][len_start] == set[i])
		{
			i++;
			len_start++;
		}
		else
			return (0);
	}
	return (1);
}
