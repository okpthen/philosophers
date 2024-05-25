/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:41:54 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/25 15:48:27 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (!ft_is_digit(*str))
			return (-1);
		i = (*str - '0') + i * 10;
		str ++;
	}
	return (i);
}
