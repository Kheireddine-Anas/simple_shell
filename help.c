#include "main.h"
/**
 * prmtdyln - int func
 *
 * Return: 0
 */
int prmtdyln(void)
{
    char *prmtdyln = "SHLL$ ";
    ssize_t writecount = 0;

    if (isatty(STDIN_FILENO) == 1)
    {
        writecount = write(STDOUT_FILENO, prmtdyln, 2);
        if (writecount == -1)
            exit(0);
    }
    return (0);
}
/**
 * rddyln - char func
 *
 * Return: pointer
 */
char *rddyln(void)
{
    ssize_t readcount = 0;
    size_t n = 0;
    char *bfrdyl = NULL;
    int i = 0;

    readcount = getline(&bfrdyl, &n, stdin);
    if (readcount == -1)
    {
        free(bfrdyl);
        if (isatty(STDIN_FILENO) != 0)
            write(STDOUT_FILENO, "\n", 1);
        exit(0);
    }
    if (bfrdyl[readcount - 1] == '\n' || bfrdyl[readcount - 1] == '\t')
        bfrdyl[readcount - 1] = '\0';
    for (i = 0; bfrdyl[i]; i++)
    {
        if (bfrdyl[i] == '#' && bfrdyl[i - 1] == ' ')
        {
            bfrdyl[i] = '\0';
            break;
        }
    }
    return (bfrdyl);
}
/**
 * _flpthbf - char func
 * @avvd: param
 * @PTHd: param
 * @cpydyl: param
 *
 * Return: pointer
 */
char *_flpthbf(char **avvd, char *PTHd, char *cpydyl)
{
    char *tokDyl, *flpthbff = NULL, *concatstr = NULL;
    static char tmpDyl[256];
    int PATHcount = 0, fullpathflag = 0, /*len = 0,*/ z = 0, toklen = 0;
    struct stat h;

    cpydyl = NULL;
    cpydyl = _strupDyl(PTHd);
    PATHcount = _spltpthDyl(cpydyl);
    tokDyl = strtok(cpydyl, ": =");
    while (tokDyl != NULL)
    {
        concatstr = _cnctDyl(tmpDyl, avvd, tokDyl);
        if (stat(concatstr, &h) == 0)
        {
            flpthbff = concatstr;
            fullpathflag = 1;
            break;
        }
        if (z < PATHcount - 2)
        {
            toklen = _strlenDyl(tokDyl);
            if (tokDyl[toklen + 1] == ':')
            {
                if (stat(avvd[0], &h) == 0)
                {
                    flpthbff = avvd[0];
                    fullpathflag = 1;
                    break;
                }
            }
        }
        z++;
        tokDyl = strtok(NULL, ":");
    }
    if (fullpathflag == 0)
        flpthbff = avvd[0];
    free(cpydyl);
    return (flpthbff);
}
/**
 * chkbLtin - int func
 * @avvd: param
 * @bfrdyl: param
 * @extsts: param
 * Return: 1 or 0
 */
int chkbLtin(char **avvd, char *bfrdyl, int extsts)
{
    int i;

    if (_strcompD(avvd[0], "env") == 0)
    {
        _envDyl();
        for (i = 0; avvd[i]; i++)
            free(avvd[i]);
        free(avvd);
        free(bfrdyl);
        return (1);
    }
    else if (_strcompD(avvd[0], "exit") == 0)
    {
        for (i = 0; avvd[i]; i++)
            free(avvd[i]);
        free(avvd);
        free(bfrdyl);
        exit(extsts);
    }
    else
        return (0);
}
/**
 * _prkprc - int func
 * @avvd: param
 * @bfrdyl: param
 * @flpthbff: param
 *
 * Return: 0 on success
 */
int _prkprc(char **avvd, char *bfrdyl, char *flpthbff)
{
    int i, status, result, extsts = 0;
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("Error");
        exit(1);
    }
    if (pid == 0)
    {
        result = execve(flpthbff, avvd, environ);
        if (result == -1)
        {
            perror(avvd[0]);
            for (i = 0; avvd[i]; i++)
                free(avvd[i]);
            free(avvd);
            free(bfrdyl);
            exit(127);
        }
    }
    wait(&status);
    if (WIFEXITED(status))
    {
        extsts = WEXITSTATUS(status);
    }
    for (i = 0; avvd[i]; i++)
        free(avvd[i]);
    free(avvd);
    free(bfrdyl);
    return (extsts);
}
