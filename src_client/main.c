/*
** main.c for PSU_2016_myirc in /home/antoine.cauquil/rendu/network/PSU_2016_myirc/client/src
** 
** Made by bufferking
** Login   <antoine.cauquil@epitech.eu>
** 
** Started on  Fri May 26 13:07:15 2017 bufferking
** Last update Sun Jun 11 22:42:28 2017 bufferking
*/

#include "irc_client.h"

volatile bool	g_client_running;

void	sig_handler(int signal)
{
  (void)signal;
  write(1, "\n", 1);
  logmsg(MSG, "%s\n", BYE_MSG);
  g_client_running = false;
}

int		logmsg(enum e_logtype mode, char *format, ...)
{
  va_list	args;

  va_start(args, format);
  if (mode == INFO)
    fprintf(stderr, "%s[+] ", ANSI_INFO);
  else if (mode == ERROR)
    fprintf(stderr, "%s[!] ", ANSI_ERROR);
  else
    fprintf(stderr, "%s[-] ", ANSI_MSG);
  vfprintf(stderr, format, args);
  va_end(args);
  fprintf(stderr, "%s", ANSI_DEFAULT);
  return (0);
}

int	print_error(const char *func_name)
{
  logmsg(ERROR, "Error in %s(): %s\n", func_name, strerror(errno));
  return (EXIT_FAILURE);
}

int	main(void)
{
  signal(SIGINT, sig_handler);
  return (client_wrapper());
}
