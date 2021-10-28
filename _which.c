#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

int main(int ac, char **av)
{
	int i, found;
	char *dir, *full_path;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s filename\n", av[0]);
		exit(98);
	}

	dir = strtok(getenv("PATH"), ":");
	found = i = 0;

	while (av[++i])
	{
		while (dir)
		{
			full_path = malloc(sizeof(char) * (strlen(dir) + strlen(av[i]) + 2));
			memcpy(full_path, dir, strlen(dir));
			memcpy((full_path + strlen(dir)), "/", 1);
			memcpy((full_path + strlen(dir) + 1), av[i], strlen(av[i]));
			memcpy((full_path + strlen(dir) + strlen(av[i]) + 1), "\0", 1);

			if (stat(full_path, &st) == 0)
			{
				printf("%s FOUND at %s\n", av[i], full_path);
				found = 1;
				free(full_path);
				break;
			}
			else
				found = 0;

			dir = strtok(NULL, ":");

			free(full_path);
		}

		if (found == 0)
			printf("%s: NOT FOUND\n", av[i]);
	}

	return (0);
}
