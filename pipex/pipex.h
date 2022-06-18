/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:29:10 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/18 17:06:34 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H
#include <stdio.h>  //perror
#include <unistd.h> //
#include <fcntl.h>  //open함수
#include <stdlib.h>

typedef struct s_arg
{
    int infile;
    int outfile;
    char **path; //경로가 : 기준으로 잘라져있다 2차원배열
    char *cmd1;
    char *cmd2;
    char *cmd_arg1;
    char *cmd_arg2;
    int pipe_fds[2]; // ??
    pid_t pid;       //fork 관련?
} t_arg;

void exit_perror(char *message, int code);
char *ft_strnstr(const char *h, const char *n, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char **ft_split(char const *s, char c);
void *ft_calloc(size_t n, size_t size);
size_t ft_strlcpy(char *dst, const char *src, size_t len);
void *ft_bzero(void *str, size_t n);

#endif