#include <stdio.h>
#include <stddef.h>

int main(int ac __attribute__((unused)), char **av)
{
	while (*(++av) != NULL)
	{
		printf("%s\n", *av);
	}
}
