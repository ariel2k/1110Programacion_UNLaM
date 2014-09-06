char *str_cpy (char *dest, const char *orig)
{
	char *inicio = dest;

	while(*orig)
		*dest++ = *orig++;

	*dest = '\0';

	return inicio;
}