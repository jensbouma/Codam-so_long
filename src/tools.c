/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 17:51:59 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/05/24 23:35:50 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "colors.h"

#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>

static void	print_console(const char *s, va_list list)
{
	while (*s)
	{
		if (*s == '%' && *s++ && *s != '%')
		{
			if (*s == 'c' || *s == 'd' || *s == 'i'
				|| *s == 'u' || *s == 'x' || *s == 'X')
				process_int(*s, va_arg(list, int));
			else if (*s == 's' || *s == 'p')
				process_char(*s, va_arg(list, char *));
		}
		else
			ft_putchar_fd(*s, STDOUT_FILENO);
		s++;
	}
}

void	error(char *msg)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	write(STDERR_FILENO, "Error\n", 6);
	if (msg)
		perror(msg);
	ft_putstr_fd(NORMAL, STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	print(const char *s, ...)
{
	va_list	list;

	va_start(list, s);
	print_console(s, list);
	va_end(list);
}

void	debug(const char *s, ...)
{
	va_list	list;

	if (DEBUG == 0)
		return ;
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	va_start(list, s);
	print_console(s, list);
	ft_putstr_fd(NORMAL, STDOUT_FILENO);
	va_end(list);
}

void	*memmory_alloccate(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count + 1);
	if (!ptr)
		error("Insane in the membrane! Insane in the brain!");
	ft_bzero(ptr, size * count);
	return (ptr);
}