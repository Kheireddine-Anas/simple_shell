#include "main.h"
/**
* tokenizeDyl - char func khadamin
* @buffer: param parametre dyalhom
*
* Return: param parametre dyalhom
*/
char **tokenizeDyl(char *buffer)
{
	char *token;
	int i = 0, wordcount = 0;
	char *delimiter = " \n";
	char **av;

	wordcount = _splitstringDyl(buffer);
	if (!wordcount)
		return (NULL);
	av = malloc((wordcount + 1) * sizeof(char *));
	if (av == NULL)
		exit(1);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		av[i] = _strdupDyl(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	av[i] = NULL;
	return (av);
}
/**
* _splitPATHdYl - int func l3adab ahamadi
* @Dylnstr: param waw parametre dyalhom
*
* Return: ra9m of PATH 3odw
*/
int _splitPATHdYl(char *Dylnstr)
{
	int i;
	int searchflag = 1;
	int wordcount = 0;

	for (i = 0; Dylnstr[i]; i++)
	{
		if (Dylnstr[i] != ':' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (Dylnstr[i + 1] == ':')
		{
			searchflag = 1;
		}
	}
	return (wordcount);
}
/**
* _PATHstrcmpDyl - int func dakchi zaz loz
* @strD1: param parametre dyalhom
* @strD2: param parametre dyalhom
*
* Return: 0 on success waqila
*/
int _PATHstrcmpDyl(const char *strD1, const char *strD2)
{
	int i;

	for (i = 0; strD2[i] != '='; i++)
	{
		if (strD1[i] != strD2[i])
			return (-1);
	}
	return (0);
}
/**
* _concatDyl - char func kamlin
* @tmp: param parametre dyalhom
* @av: param parametre dokil
* @tok: param parametre maart
*
* Return: 0 on ila njah
*/
char *_concatDyl(char *tmp, char **av, char *tok)
{
	int len = 0;

	_memsetDyl(tmp, 0, 256);
	len = _strlenDyl(tok) + _strlenDyl(av[0]) + 2;
	_strcatDyl(tmp, tok);
	_strcatDyl(tmp, "/");
	_strcatDyl(tmp, av[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
