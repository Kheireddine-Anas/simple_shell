#include "main.h"
/**
* promptDyl - int func
*
* Return: 0
*/
int promptDyl(void)
{
	char *promptDyl = "$ ";
	ssize_t writecount = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, promptDyl, 2);
		if (writecount == -1)
			exit(0);
	}
	return (0);
}
/**
* _readDyl - char func
*
* Return: pointer
*/
char *_readDyl(void)
{
	ssize_t readcount = 0;
	size_t n = 0;
	char *buffer = NULL;
	int i = 0;

	readcount = getline(&buffer, &n, stdin);
	if (readcount == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[readcount - 1] == '\n' || buffer[readcount - 1] == '\t')
		buffer[readcount - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
/**
* _fullpathbfDyl - char func
* @av: param
* @PATH: param
* @copy: param
*
* Return: pointer
*/
char *_fullpathbfDyl(char **av, char *PATH, char *copy)
{
	char *tok, *flpthbfD = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathflag = 0, /*len = 0,*/ z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _strdupDyl(PATH);
	PATHcount = _splitPATHdYl(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _concatDyl(tmp, av, tok);
		if (stat(concatstr, &h) == 0)
		{
			flpthbfD = concatstr;
			fullpathflag = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			toklen = _strlenDyl(tok);
			if (tok[toklen + 1] == ':')
			{
				if (stat(av[0], &h) == 0)
				{
					flpthbfD = av[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		z++;
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		flpthbfD = av[0];
	free(copy);
	return (flpthbfD);
}
/**
* checkbuiltinsDyl - int func
* @av: param
* @buffer: param
* @exitstatus: param
* Return: 1 or 0
*/
int checkbuiltinsDyl(char **av, char *buffer, int exitstatus)
{
	int i;

	if (_strcmpDyl(av[0], "env") == 0)
	{
		_Dylenv();
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		return (1);
	}
	else if (_strcmpDyl(av[0], "exit") == 0)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}
/**
* _forkprocesDyl - int func
* @av: param
* @buffer: param
* @flpthbfD: param
*
* Return: 0 on success
*/
int _forkprocesDyl(char **av, char *buffer, char *flpthbfD)
{
	int i, status, result, exitstatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result = execve(flpthbfD, av, environ);
		if (result == -1)
		{
			perror(av[0]);
			for (i = 0; av[i]; i++)
				free(av[i]);
			free(av);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
	free(buffer);
	return (exitstatus);
}
