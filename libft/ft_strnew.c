/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:47:47 by bhoth             #+#    #+#             */
/*   Updated: 2019/09/20 20:51:41 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*m;

	if (size + 1 <= 0)
		return (NULL);
	m = (char *)malloc(size + 1);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, size + 1);
	return (m);
}
