#include "main.h"
/**
* _strdupDyl - char func deyalha hadi
* @Dylnstr: param parametre dyalhom
*
* Return: pointer mart lihom
*/
char *_strdupDyl(char *Dylnstr)
{
	int i;
	char *dest_str;

	if (Dylnstr == NULL)
		return (NULL);
	for (i = 0; Dylnstr[i] != '\0'; i++)
		;
	dest_str = malloc(sizeof(char) * (i + 1));
	if (dest_str == NULL)
		return (NULL);
	for (i = 0; Dylnstr[i] != '\0'; i++)
	{
		dest_str[i] = Dylnstr[i];
	}
	dest_str[i] = '\0';
	return (dest_str);
}
/**
* _splitstringDyl - int func fihom kamlin
* @Dylnstr: param may mkanch
*
* Return: param parametre dyalhom
*/
int _splitstringDyl(char *Dylnstr)
{
	int i;
	int searchflag = 1;
	int wordcount = 0;

	for (i = 0; Dylnstr[i]; i++)
	{
		if (Dylnstr[i] != ' ' && searchflag == 1)
		{
			wordcount += 1;
			searchflag = 0;
		}
		if (Dylnstr[i + 1] == ' ')
			searchflag = 1;
	}
	return (wordcount);
}
/**
* _strcmpDyl - int func to long 3lina
* @strD1: param parametre dyalhom
* @strD2: param parametre dyalhom
* Return: int chi ra9am
*/
int _strcmpDyl(const char *strD1, const char *strD2)
{
	while ((*strD1 != '\0' && *strD2 != '\0') && *strD1 == *strD2)
	{
		strD1++;
		strD2++;
	}
	if (*strD1 == *strD2)
		return (0);
	else
		return (*strD1 - *strD2);
}
/**
* _strcatDyl - char func awdi ach ghadi
* @dest: param parametre dyalhom
* @src: param parametre dyalhom
* i - param parametre dyalhom jdid
* j - param jdid hadchi
* Return: char chi harf hada
*/
char *_strcatDyl(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
/**
* _strlenDyl - int func bazaf deyl
* @s: param khadma
* i - param parametre dyalhom
* Return: int waqila
*/
int _strlenDyl(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
