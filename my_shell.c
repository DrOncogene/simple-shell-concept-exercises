#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char *av[])
{
	char *comm, *comm_cpy, **argv;
	int argc;
	size_t n;

	argc = n = 0;
	printf("my_shell$ ");
	comm = NULL;
	getline(&comm, &n, stdin);
	*(comm + strlen(comm) - 1) = '\0';
	comm_cpy = strdup(comm);

	argv = get_argv(comm, comm_cpy);
	while (argv[argc])
		argc++;

	execute(argv);

	free(comm_cpy);
	free(argv);

	execve(av[0], av, NULL);

	return (0);
}

char **get_argv(char *str, char *str_cpy)
{
	char **arr;
	unsigned int n_words, i;

	if (str == NULL)
		return (NULL);

	n_words = 0;

	if (strtok(str, " "))
		n_words++;
	while (strtok(NULL, " "))
		n_words++;

	arr = malloc(sizeof(int) * 2 * (n_words + 1));

	arr[0] = strtok(str_cpy, " ");
	for (i = 1; i < n_words; i++)
		*(arr + i) = strtok(NULL, " ");

	*(arr + n_words) = NULL;

	free(str);
	return (arr);
}

int execute(char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("Error");
		return (1);
	}

	if (child == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("my_shell: Error");
			return (1);
		}
	}
	else
		wait(&status);

	return (0);
}
