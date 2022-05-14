/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:19:37 by abbahoua          #+#    #+#             */
/*   Updated: 2022/04/24 00:25:13 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strcmp(char *s1, char *s2);
size_t	ft_sstrlen(char **str);
char	**ft_split(char *s, char c);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif