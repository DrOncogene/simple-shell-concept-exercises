#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main()
{
	char *line_buff = NULL;
	size_t n = 0;

	printf("$ ");
	n = getline(&line_buff, &n, stdin);
	printf("%ld: %s", n, line_buff);
	free(line_buff);

	return (0);
}
