/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:16:51 by bhoth             #+#    #+#             */
/*   Updated: 2019/10/15 20:15:02 by bhoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*temp;
	size_t	len;

	res = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			temp = res;
			while (*s1)
			{
				*temp = *s1;
				temp++;
				s1++;
			}
			ft_strcpy(temp, (char*)s2);
			return (res);
		}
		return (res);
	}
	return (NULL);
}
