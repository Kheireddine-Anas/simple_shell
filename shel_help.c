#include "main.h"
/**
 * _strupDyl - char func
 * @strDyln: param
 *
 * Return: pointer
 */
char *_strupDyl(char *strDyln)
{
    int i;
    char *dest_str;

    if (strDyln == NULL)
        return (NULL);
    for (i = 0; strDyln[i] != '\0'; i++)
        ;
    dest_str = malloc(sizeof(char) * (i + 1));
    if (dest_str == NULL)
        return (NULL);
    for (i = 0; strDyln[i] != '\0'; i++)
    {
        dest_str[i] = strDyln[i];
    }
    dest_str[i] = '\0';
    return (dest_str);
}
/**
 * _splstrD - int func
 * @strDyln: param
 *
 * Return: param
 */
int _splstrD(char *strDyln)
{
    int i;
    int searchflag = 1;
    int wordcount = 0;

    for (i = 0; strDyln[i]; i++)
    {
        if (strDyln[i] != ' ' && searchflag == 1)
        {
            wordcount += 1;
            searchflag = 0;
        }
        if (strDyln[i + 1] == ' ')
            searchflag = 1;
    }
    return (wordcount);
}
/**
 * _strcompD - int func
 * @st1: param
 * @st2: param
 * Return: int
 */
int _strcompD(const char *st1, const char *st2)
{
    while ((*st1 != '\0' && *st2 != '\0') && *st1 == *st2)
    {
        st1++;
        st2++;
    }
    if (*st1 == *st2)
        return (0);
    else
        return (*st1 - *st2);
}
/**
 * _strctDyl - char func
 * @dstDyl: param
 * @srcBnd: param
 * i - param
 * j - param
 * Return: char
 */
char *_strctDyl(char *dstDyl, char *srcBnd)
{
    int i;
    int j;

    for (i = 0; dstDyl[i] != '\0'; i++)
        ;
    for (j = 0; srcBnd[j] != '\0'; j++, i++)
        dstDyl[i] = srcBnd[j];
    dstDyl[i] = '\0';
    return (dstDyl);
}
/**
 * _strlenDyl - int func
 * @sDy: param
 * i - param
 * Return: int
 */
int _strlenDyl(char *sDy)
{
    int i;

    for (i = 0; sDy[i]; i++)
        ;
    return (i);
}
