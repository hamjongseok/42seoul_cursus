/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:09:52 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/07/12 23:20:26 by hamjongseog      ###   ########.fr       */
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
    if (*envp == NULL)
        exit_perror("PATH error", 127);
    path = *envp + 5;
    return (ft_split(path, ':'));
}

char *get_cmd_argv(char **path, char *cmd)
{
    int i;
    int fd;
    char *path_cmd;
    char *tmp;

    fd = access(cmd, X_OK);
    if (fd != -1)
        return (cmd);
    path_cmd = ft_strjoin("/", cmd);
    printf("path_cmd= %s\n", path_cmd);
    i = 0;
    while (path[i])
    {
        tmp = ft_strjoin(path[i], path_cmd);
        printf("%s\n", tmp);
        fd = access(tmp, X_OK);
        if (fd != -1)
        {
            free(path_cmd);
            return (tmp);
        }
        close(fd);
        free(tmp);
        i++;
    }
    free(path_cmd);
    return (NULL);
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
    arg->path = get_path_envp(envp); //path에다가 envp안의 경로를 넣어줌 cmd1 cmd2를 실행하기위해
    arg->cmd_arg1 = ft_split(av[2], ' ');
    arg->cmd_arg2 = ft_split(av[3], ' '); //공백을 기준으로 잘라서 넣어줌
    arg->cmd1 = get_cmd_argv(arg->path, arg->cmd_arg1[0]);
    arg->cmd2 = get_cmd_argv(arg->path, arg->cmd_arg2[0]);
    if (arg->cmd1 == NULL || arg->cmd2 == NULL)
    {
        result = 127;
        perror("command not found");
    }
    return (result);
}

int main(int ac, char *av[], char *envp[])
{
    t_arg arg;
    int result;

    if (ac != 5) //5개가 아니라면 예외처리
        exit_perror("argument error", 1);
    result = arg_parse(&arg, av, envp);
    return (0);
}
