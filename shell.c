#include "main.h"
/**
 * main - int func
 *
 * Return: 0 on success
 */
int main(void)
{
    char *flpthbff = NULL, *cpydyl = NULL, *bfrdyl = NULL;
    char *PTHd = NULL;
    char **avvd;
    int extsts = 0;

    signal(SIGINT, SIG_IGN);
    PTHd = _gtenvDyl("PTHd");
    if (PTHd == NULL)
        return (-1);
    while (1)
    {
        avvd = NULL;
        prmtdyln();
        bfrdyl = rddyln();
        if (*bfrdyl != '\0')
        {
            avvd = tknszDyl(bfrdyl);
            if (avvd == NULL)
            {
                free(bfrdyl);
                continue;
            }
            flpthbff = _flpthbf(avvd, PTHd, cpydyl);
            if (chkbLtin(avvd, bfrdyl, extsts) == 1)
                continue;
            extsts = _prkprc(avvd, bfrdyl, flpthbff);
        }
        else
            free(bfrdyl);
    }
    return (0);
}
