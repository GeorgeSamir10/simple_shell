/**
 * _atoi - convert a string to an integer.
 * @str: pointer to string to be converted.
 *
 * Return: converted integer value
 */
int _atoi(char *str)
{
	unsigned int result;
	int idx, sign;

	sign = 1;
	result = 0;
	for (idx = 0; str[idx] != '\0'; idx++)
	{
		if (str[idx] == '-')
		{
			sign = sign * -1;
		}
		if (str[idx] > '9' || str[idx] < '0')
		{
			continue;
		}
		else
		{
			result = (result * 10) + (str[idx] - '0');
			if (str[idx + 1] == ' ')
			{
				break;
			}
		}
	}
	return (result * sign);
}
