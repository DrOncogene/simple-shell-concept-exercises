#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

int main(void)
{
	pid_t child, father;
	int status, i;
	char s[] = "/bin/ls";
	char *av[] = {s, "-l", "/tmp", NULL};

	father = getpid();
	for (i = 1; i < 6; i++)
	{
		printf("Father: %d\n", father);
		child = fork();
		if (child == -1)
			perror("Error");

		if (child == 0)
		{
			printf("Child %d: %d\n", i, child);
			if (execve(av[0], av, NULL) == -1)
				perror("Error");
		}
		else
			wait(&status);
	}

	return (0);
}
