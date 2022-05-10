/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:29:24 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/05/10 22:51:37 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void ft_make_list(t_stack *head, long long *arr, int cnt) //a가 헤드임
{
    int idx;
    t_stack *new_node;

    idx = 0;
    while (idx < cnt) //0부터 arrsize만큼 돌린다
    {
        new_node = (t_stack *)malloc(sizeof(t_stack)); //노드 생성
        if (!new_node)                                 //에러날경우 예외처리
            ft_error(0);
        if (head->next == NULL) //처음에 여기로 들어온다.
        {
            new_node->data = arr[idx++]; //새로운 노드의 data에 arr[0]넣음
            new_node->next = NULL;       //next는 널값
            new_node->prev = head;       //그전은 a를 가르킴
            head->next = new_node;       //a의 다음은 생성한 노드 가르킴
        }
        else //두번째 노드부터 여기로들어와서 FIFO를 위해 처음들어온노드를 계속 마지막으로 밀어줌
        {
            new_node->data = arr[idx++];     //두번째 생성한 노드에 data arr[1]을 넣음
            new_node->next = head->next;     //생성노드의 다음값이 1번노드를가르킴
            new_node->next->prev = new_node; //1번노드의 prev값을 생성노드
            new_node->prev = head;           //생성노드의 prev값을 head가르킴
            head->next = new_node;           //head의 다음은 생성노드
        }
    } //양방향 연결리스트 (스택) 생성
}