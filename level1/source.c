/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcharbo <frcharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:38:42 by frcharbo          #+#    #+#             */
/*   Updated: 2024/11/22 22:55:35 by frcharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    char pass[100];

    printf("Please enter key: ");
    scanf("%99s", &input);
    
    if (strcmp("__stack_check\0", &input))
        printf("Nope.\n");
    else
        printf("Good job.\n");
    return (0);
}