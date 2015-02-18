/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:03:08 by mdarriga          #+#    #+#             */
/*   Updated: 2015/02/13 17:15:03 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int val, int base, int output_size)
{
	char			*buffer;
	char			*p;
	char			*table;
	unsigned int	unsigned_val;

	buffer = (char *)malloc(sizeof(char) * (output_size + 1));
	table = "0123456789abcdefghijklmnopqrstuvwxyz";
	unsigned_val = (unsigned int)val;
	if (base > 36 || base < 2)
		return (NULL);
	buffer[output_size + 1] = 0;
	p = buffer + output_size - 1;
	*p = '0';
	if (unsigned_val > 0)
	{
		while (unsigned_val > 0)
		{
			*p-- = table[unsigned_val % base];
			unsigned_val = unsigned_val / base;
			if (p < buffer)
				break ;
		}
		p++;
	}
	return (ft_strdup(p));
}
