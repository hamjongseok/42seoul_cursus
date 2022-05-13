/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:55:26 by jham              #+#    #+#             */
/*   Updated: 2022/05/14 00:41:13 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_push_first(t_stack *head, int data)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        ft_error(0);
    if (head->next == NULL) //?한번 생각 해보자 담에
    {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = head;
        head->next = new_node;
    }
    else
    {
        new_node->data = data;
        new_node->next = head->next;
        head->next->prev = new_node;
        new_node->prev = head;
        head->next = new_node;
    }
}

int ft_size(t_stack *head)
{
    t_stack *tmp;
    int size;

    size = 0;
    tmp = head->next;
    while (tmp) //tmp가 널을 만날때까지 노드의 길이를 구함
    {
        tmp = tmp->next;
        size += 1;
    }
    return (size);
}
void ft_push_last(t_stack *head, int data) //a 노드와 7을 가져옴
{
    t_stack *new_node;
    t_stack *tmp_last;

    new_node = (t_stack *)malloc(sizeof(t_stack)); //동적할당함
    if (!new_node)                                 //예외처리
        ft_error(0);
    tmp_last = ft_find_last_lst(head); // 마지막 노드
    if (head->next == NULL)            //  b노드가여기들어오네
    {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = head;
        head->next = new_node;
    }
    else //여기로들어옴
    {
        new_node->data = data;     //새로생성한 노드에 7을 넣어줌
        new_node->next = NULL;     //새로생성한 노드의 다음을 널값
        new_node->prev = tmp_last; //노드의 전을 마지막 노드와 이어줌
        tmp_last->next = new_node; // 마지막 노드의 다음을 새로 생성한 노드
    }
}

void ft_pop(t_stack *head) //pop == 꺼내다 , 근데 스택의 마지막 에 들어온걸 빼야하는건데?
{
    t_stack *del;

    del = head->next; //7을 가지고있는 첫번째노드를 del에 넣음
    if (del == NULL)
        return;
    if (del->next == NULL) // ? 이게있어야댐? 어차피 null아닐텐데 다른곳에서 쓰이는거 확인해봐라
    {
        head->next = del->next;
        free(del);
    }
    else //여기만보면댐 , 7을 가지고있는 노드는 사라지는게 아닌가? 없어지는데
    {
        del->next->prev = head;
        head->next = del->next;
        free(del);
    }
}

void ft_pop_last(t_stack *head)
{
    t_stack *del;

    del = head->next;
    if (del == NULL)
        return;
    else
    {
        del = ft_find_last_lst(head);
        del->prev->next = NULL;
        free(del);
    }
}