int main(void)
{
	int i;
	char str[] = "My name is Nasir Abdulrasheed";
	char **arr = make_av(str);

	if (arr == NULL)
	{
		printf("Returned NULL\n");
		return (1);
	}

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}

	free(arr);
	return (0);
}
