#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int prmtdyln(void);
char *rddyln(void);
char *_flpthbf(char **avvd, char *PTHd, char *cpydyl);
int chkbLtin(char **avvd, char *bfrdyl, int extsts);
int _prkprc(char **avvd, char *bfrdyl, char *flpthbff);


char *_strupDyl(char *strDyln);
int _splstrD(char *strDyln);
int _strcompD(const char *st1, const char *st2);
char *_strctDyl(char *dstDyl, char *srcBnd);
int _strlenDyl(char *sDy);


char **tknszDyl(char *bfrdyl);
int _spltpthDyl(char *strDyln);
int _PTHstrDyl(const char *st1, const char *st2);
char *_cnctDyl(char *tmpDyl, char **avvd, char *tokDyl);


char *_gtenvDyl(const char *nmDyln);
int _envDyl(void);
void _ptsDyl(char *strDyln);
int _putchar(char c);
char *_mmsetDyl(char *sDy, char bDy, unsigned int n);

#endif
