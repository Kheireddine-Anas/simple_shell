#include "main.h"
/**
 * _getenv- the functin for dd and were you go.
 * @name: hada barrff.
 * Return: kolo hada min ajli hada.
 */

char *_getenv(const char *name)
{
	int i = 0;
	char *split;
	char *value;

	while (environ[i])
	{
		split = strtok(environ[i], "=");
	if (strcmp(split, name) == 0)
	{
		value = strtok(NULL, "\n");
		return (value);
	}
	i++;
	}
	return (NULL);
}

/**
 * spt_args- the blane hawa hadak.
 * @buffer: kolo howa hadak bach tbri.
 * @del: mali tji rom ou sir.
 * Return: Mahada ta hada.
 */

char **spt_args(char *buffer, char *del)
{
	char **toks;
	char *tok;
	int i = 0;

	toks = malloc(sizeof(char *) * 1024);
	tok = strtok(buffer, del);
	while (tok)
	{
		toks[i] = tok;
		tok = strtok(NULL, del);
		i++;
	}
	toks[i] = NULL;
	return (toks);
}
