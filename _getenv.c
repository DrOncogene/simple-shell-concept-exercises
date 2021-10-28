#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *_getenv(const char *name);

int main(int ac, char **av)
{
	const char *env_var;

	if (ac != 2)
	{
		printf("Usage: %s variablename\n", av[0]);
		exit(98);
	}

	env_var = _getenv(av[1]);
	printf("%s\n", env_var);

	return (0);
}

char *_getenv(const char *name)
{
	extern char **environ;
	int i, found;
	unsigned int j;

	found = i = 0;
	while (environ[i])
	{
		if (*(environ[i]) == *name)
		{
			for (j = 1; j < strlen(name); j++)
			{
				if (*(environ[i] + j) == *(name + j))
				{
					found = 1;
				}
				else
				{
					found = 0;
					break;
				}
			}
		}

		if (found == 1)
			break;

		i++;
	}

	return (environ[i] + ++j);
}
