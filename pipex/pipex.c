/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:09:52 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/18 17:07:50 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

char **get_path_envp(char *envp[]) // 환경변수에서 PATH를 찾아서 PATH= 이후의 글자를 ft_split 으로 : 로 나눠서 저장한다.
{
    char *path;
    int i;

    i = 0;

    while (*envp && ft_strncmp("PATH=", *envp, 5))
        envp++;
    path = *envp + 5;
    while (path[i])
    {
        printf("%c", path[i]);
        i++;
    }
    return (ft_split(path, ':'));
}

int arg_parse(t_arg *arg, char *av[], char *envp[])
{
    int result;

    result = 1;
    arg->infile = open(av[1], O_RDONLY); //infile을 open으로 읽는다. fd값이 저장
    if (arg->infile == -1)               //-1은 에러이므로 에러처리
        perror("infile");
    arg->outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (arg->outfile == -1)
        exit_perror("outfile", 1);
    arg->path = get_path_envp(envp);
    int i = 0;
    while (arg->path[i])
    {
        printf("PATH = ! %s\n", arg->path[i]);
        i++;
    }

    return (0);
}

int main(int ac, char *av[], char *envp[])
{
    t_arg arg;
    int result;

    if (ac != 1) //5개가 아니라면 예외처리
        exit_perror("argument error", 1);
    result = arg_parse(&arg, av, envp);
    return (0);
}
