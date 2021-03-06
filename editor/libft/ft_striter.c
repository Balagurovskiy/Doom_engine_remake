/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkachano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:10:28 by mkachano          #+#    #+#             */
/*   Updated: 2017/11/11 23:10:30 by mkachano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		if ((ft_strlen(s) > 0) && (f != NULL))
		{
			while (*s != '\0')
			{
				(*f)(s);
				s++;
			}
		}
	}
}
