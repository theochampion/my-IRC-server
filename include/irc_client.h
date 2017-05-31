/*
** irc_client.h for PSU_2016_myirc in /home/bufferking/rendu/network/PSU_2016_myirc
** 
** Made by bufferking
** Login   <antoine.cauquil@epitech.eu>
** 
** Started on  Fri May 26 14:00:13 2017 bufferking
** Last update Wed May 31 19:30:59 2017 
*/

#ifndef IRC_CLIENT_H_
#define IRC_CLIENT_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define DEFAULT_PORT 6667

#define USAGE_FRMT "usage : %s\n"
#define USAGE_SERVER "/server $host[:$port]"
#define USAGE_NICK "/nick $nickname"

#define FRMT_NICK "NICK %s\n"

#define BYE_MSG "Thank you for using the IRC client r2-38501"

enum	e_logtype
  {
    INFO,
    ERROR,
    MSG
  };

typedef			struct s_server
{
  int			sd;
  struct sockaddr_in	addr;
}			t_server;

/* typedef			struct s_command */
/* { */
/*   char	*cmd; */
/*   char	*a1; */
/*   char	*a2: */
/*   //char	*a3; */
/* }			t_command; */

typedef int(*t_comm_handler)(t_server*, char**);

// main.c //
int		logmsg(enum e_logtype mode, char *format, ...);
int		print_error(const char *func_name);
// wrapper.c //
int		cmd_quit(t_server *srv, char **cmd);
int		cmd_server(t_server *srv, char **cmd);
int		cmd_nick(t_server *srv, char **cmd);
int		client_wrapper(void);

#endif /* !IRC_CLIENT_H_ */