#include "main.h"
/**
 * tknszDyl - char func
 * @bfrdyl: param
 *
 * Return: param
 */
char **tknszDyl(char *bfrdyl)
{
    char *token;
    int i = 0, wordcount = 0;
    char *delimiter = " \n";
    char **avvd;

    wordcount = _splstrD(bfrdyl);
    if (!wordcount)
        return (NULL);
    avvd = malloc((wordcount + 1) * sizeof(char *));
    if (avvd == NULL)
        exit(1);
    token = strtok(bfrdyl, delimiter);
    while (token != NULL)
    {
        avvd[i] = _strupDyl(token);
        token = strtok(NULL, delimiter);
        i++;
    }
    avvd[i] = NULL;
    return (avvd);
}
/**
 * _spltpthDyl - int func
 * @strDyln: param
 *
 * Return: number of PTHd members
 */
int _spltpthDyl(char *strDyln)
{
    int i;
    int searchflag = 1;
    int wordcount = 0;

    for (i = 0; strDyln[i]; i++)
    {
        if (strDyln[i] != ':' && searchflag == 1)
        {
            wordcount += 1;
            searchflag = 0;
        }
        if (strDyln[i + 1] == ':')
        {
            searchflag = 1;
        }
    }
    return (wordcount);
}
/**
 * _PTHstrDyl - int func
 * @st1: param
 * @st2: param
 *
 * Return: 0 on success
 */
int _PTHstrDyl(const char *st1, const char *st2)
{
    int i;

    for (i = 0; st2[i] != '='; i++)
    {
        if (st1[i] != st2[i])
            return (-1);
    }
    return (0);
}
/**
 * _cnctDyl - char func
 * @tmpDyl: param
 * @avvd: param
 * @tokDyl: param
 *
 * Return: 0 on success
 */
char *_cnctDyl(char *tmpDyl, char **avvd, char *tokDyl)
{
    int len = 0;

    _mmsetDyl(tmpDyl, 0, 256);
    len = _strlenDyl(tokDyl) + _strlenDyl(avvd[0]) + 2;
    _strctDyl(tmpDyl, tokDyl);
    _strctDyl(tmpDyl, "/");
    _strctDyl(tmpDyl, avvd[0]);
    tmpDyl[len - 1] = '\0';
    return (tmpDyl);
}
