#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t ppid, pid;

	ppid = getppid();
	pid = getpid();
	printf("Parent: %u, Child: %u\n", ppid, pid);

	return (0);
}
