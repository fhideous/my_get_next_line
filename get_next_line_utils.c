/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:33:52 by fhideous          #+#    #+#             */
/*   Updated: 2020/11/20 17:34:46 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *s)
{
	size_t cnt;

	cnt = 0;
	while (*(s + cnt) != '\0')
		cnt++;
	return (cnt);
}

void			*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (0);
	ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (len--)
		*ptr++ = *src_ptr++;
	return (dst);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*conc_str;
	size_t		s1_len;
	size_t		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	conc_str = (char *)malloc(s1_len + s2_len + 1);
	if (!conc_str)
		return (NULL);
	ft_memcpy(conc_str, s1, s1_len);
	ft_memcpy(conc_str + s1_len, s2, s2_len);
	*(conc_str + s1_len + s2_len) = '\0';
	free((char*)s1);
	free((char*)s2);
	return (conc_str);
}
