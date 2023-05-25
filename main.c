#include "main.h"
/**
 * _gtenvDyl - char func
 * @nmDyln: param
 *
 * Return: NULL
 */
char *_gtenvDyl(const char *nmDyln)
{
    int i, result;

    for (i = 0; environ[i]; i++)
    {
        result = _PTHstrDyl(nmDyln, environ[i]);
        if (result == 0)
        {
            return (environ[i]);
        }
    }
    return (NULL);
}
/**
 * _envDyl - prints the environ
 *
 * Return: 0 on success
 */
int _envDyl(void)
{
    int i;

    for (i = 0; environ[i]; i++)
        _ptsDyl(environ[i]);
    return (0);
}
/**
 * _ptsDyl - prints a string
 * @strDyln: string to print
 */
void _ptsDyl(char *strDyln)
{
    int c;

    for (c = 0; strDyln[c] != '\0'; c++)
        _putchar(strDyln[c]);
    _putchar('\n');
}
/**
 * _putchar - prints a character
 * @c: character to print
 *
 * Return: return value of write syscall
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
/**
 * _mmsetDyl - char func
 * @sDy: param
 * @bDy: param
 * @n: param
 * Return: array
 */
char *_mmsetDyl(char *sDy, char bDy, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
    {
        sDy[i] = bDy;
    }
    return (sDy);
}
