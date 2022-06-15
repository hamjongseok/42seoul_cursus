/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:29:10 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/15 16:09:47 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_arg
{
    int infile;
    int outfile;
    char **path;
    char *cmd1;
    char *cmd2;
    char *cmd_arg1;
    char *cmd_arg2;
    int pipe_fds[2]; // ??
    pid_t pid;       //fork 관련?
} t_arg;

void exit_perror(char *message, int code);

#endif