#include "main.h"
#include <stdio.h>

/**
 * close_file - close
 * @fd: file
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_from - open
 * @file: name
 *
 * Return: fd
 */
int open_from(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}
	return (fd);
}

/**
 * open_to - open
 * @file: name
 *
 * Return: fd
 */
int open_to(char *file)
{
	int fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (fd);
}

/**
 * copy_file - copy
 * @fd_from: from
 * @fd_to: to
 * @from: name
 * @to: name
 */
void copy_file(int fd_from, int fd_to, char *from, char *to)
{
	ssize_t r, w;
	char buf[1024];

	r = read(fd_from, buf, 1024);
	while (r > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
			exit(99);
		}
		r = read(fd_from, buf, 1024);
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
		exit(98);
	}
}

/**
 * main - copy
 * @ac: count
 * @av: args
 *
 * Return: 0
 */
int main(int ac, char *av[])
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open_from(av[1]);
	fd_to = open_to(av[2]);
	copy_file(fd_from, fd_to, av[1], av[2]);
	close_file(fd_from);
	close_file(fd_to);
	return (0);
}
