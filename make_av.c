#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char **make_av(char *str)
{
	char **arr, *str_cpy;
	unsigned int n_words, i;

	if (str == NULL)
		return (NULL);

	str_cpy = strdup(str);
	n_words = 0;

	if (strtok(str_cpy, " "))
		n_words++;
	while (strtok(NULL, " "))
		n_words++;

	arr = malloc(sizeof(int) * 2 * (n_words + 1));

	arr[0] = strtok(str, " ");
	for(i = 1; i < n_words; i++)
		*(arr + i) = strtok(NULL, " ");

	*(arr + n_words) = NULL;

	free(str_cpy);
	return (arr);
}

int main(int argc, char **argv)
{
	int i;

	if (argc != 2)
	{
		printf("Usage: %s string\n", argv[0]);
		exit(98);
	}
	char **arr = make_av(argv[1]);

	if (arr == NULL)
	{
		printf("Returned NULL\n");
		return (1);
	}

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}

	free(arr);
	
	return (0);
}
