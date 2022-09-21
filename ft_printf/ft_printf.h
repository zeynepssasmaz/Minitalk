/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsasmaz <zsasmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:43:55 by zsasmaz           #+#    #+#             */
/*   Updated: 2022/09/20 21:43:59 by zsasmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_select(va_list args, const char select);
int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_number(int n);
int	ft_print_unumber(unsigned int n);
int	ft_hex(unsigned long p, char *base, int check, int baselen);
#endif
