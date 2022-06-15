/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:09:52 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/15 16:11:59 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int arg_parse(t_arg *arg, char *av[], char *envp[])
{
    int result;

    result = 1;
    arg->infile = open(av[1], O_RDONLY);
    if (arg->infile == -1)
        perror("infile");
    arg->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (arg->outfile == -1)
        exit_perror("outfile", 1);
}

int main(int ac, char *av[], char *envp[])
{
    t_arg arg;
    int result;

    if (ac != 5)
        exit_perror("argument error", 1);
    result = arg_parse(&arg, av, envp);
    return (0);
}