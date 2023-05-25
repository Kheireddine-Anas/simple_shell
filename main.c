#include "maindl.h"
/**
* _getenvDyl - char the function the slution pro.
* @name: parammtre the pro.
*
* Return: NULL
*/
char *_getenvDyl(const char *name)
{
int i, result;

for (i = 0; environ[i]; i++)
{
	result = _PATHstrcmpDyl(name, environ[i]);
	if (result == 0)
	{
		return (environ[i]);
	}
}
return (NULL);
}
/**
* _Dylenv - prints thee environment.
*
* Return: 0 on success.
*/
int _Dylenv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_putsDyl(environ[i]);
	return (0);
}
/**
* _putsDyl - prints string go pro.
* @Dylnstr: string in the printing.
*/
void _putsDyl(char *Dylnstr)
{
	int c;

	for (c = 0; Dylnstr[c] != '\0'; c++)
		_Dylnaptch(Dylnstr[c]);
	_Dylnaptch('\n');
}
/**
* _Dylnaptch - prints in characterst the pro.
* @c: character the printing are pro.
*
* Return: return the value of write syscall pro.
*/
int _Dylnaptch(char c)
{
	return (write(1, &c, 1));
}
/**
* _memsetDyl - char func
* @s: param
* @b: param
* @n: param
* Return: array
*/
char *_memsetDyl(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
