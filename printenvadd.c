#include <unistd.h>
#include <stdio.h>

int main(int ac __attribute__((unused)),
		char **av __attribute__((unused)), char **env)
{
	extern char **environ;

	printf("main env: %p\n", (void *)env);
	printf("global env: %p\n", (void *)environ);

	return (0);
}
