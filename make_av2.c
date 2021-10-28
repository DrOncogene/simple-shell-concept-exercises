#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void save_in_arr(char **, char *, const char *);

char **create_av(char *str, const char *delim)
{
	char **arr, *str_h;
	unsigned int len_delim, words, i;

	if (str == NULL || delim == NULL || *str == 0 || *delim == 0)
		return (NULL);
	str_h = str;
	words = 0;
	len_delim = strlen(delim);
	while (*str != 0)
	{
		if (*str == *delim)
		{
			for (i = 0; i < len_delim; i++)
				if (*(str + i) != *(delim + i))
					break;

			str += (i - 1);
		}
		else
		{
			i = 0;
			while (*(str + i) != *delim && *(str + i) != 0)
				i++;

			if (i != 0)
			{
				words++;
				str += (i - 1);
			}
		}

		str++;
	}

	arr = malloc(sizeof(int) * 2 * (words + 1));
	save_in_arr(arr, str_h, delim);
	arr[words] = NULL;

	return (arr);
}

void save_in_arr(char **arr, char *str, const char *delim)
{
	unsigned int len_delim, n, i;

	n = 0;
	len_delim = strlen(delim);
	while (*str != 0)
	{
		if (*str == *delim)
		{
			for (i = 0; i < len_delim; i++)
				if (*(str + i) != *(delim + i))
					break;

			str += (i - 1);
		}
		else
		{
			i = 0;
			while (*(str + i) != *delim && *(str + i) != 0)
				i++;

			if (i != 0)
			{
				arr[n] = malloc(sizeof(char) * i + 1);
				memcpy(arr[n], str, i);
				*(arr[n] + i) = 0;
				n++;
				str += (i - 1);
			}
		}

		str++;
	}
}

int main(void)
{
	int i;
	char str[] = "This program fraustrated me a lot";
	char **arr = create_av(str, " ");

	if (arr == NULL)
	{
		printf("Returned NULL\n");
		return (1);
	}

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}

	free(arr);
	return (0);
}
