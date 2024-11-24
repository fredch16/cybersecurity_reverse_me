/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcharbo <frcharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:13:43 by frcharbo          #+#    #+#             */
/*   Updated: 2024/11/23 22:24:26 by frcharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void no(void)
{
	puts("Nope.");
	exit(1);
}

void ok(void)
{
	puts("Good job.");
	return;
}

// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int main(void)
{
	size_t strlen_retval;
	int inbuff_3xi;
	bool offset_gt_ib;
	char ascii_code[4];
	char input_buffer [24];
	char delibera_buffer [9];
	uint inbuff_offset;
	int i;
	printf("Please enter key: ");

	if (!scanf("%23s", input_buffer))
		no();

	if (input_buffer[1] != '0')
		no();

	if (input_buffer[0] != '0')
		no();

	fflush(stdin);
	memset(delibera_buffer,0,9);
	delibera_buffer[0] = 'd';
	ascii_code[3] = 0;
	inbuff_offset = 2;
	i = 1;
	while( true )
	{
		strlen_retval = strlen(delibera_buffer);
		offset_gt_ib = false;
		if (strlen_retval < 8)
		{
			strlen_retval = strlen(input_buffer);
			offset_gt_ib = inbuff_offset < strlen_retval;
		}
		if (!offset_gt_ib)
			break;
		ascii_code[0] = input_buffer[inbuff_offset];
		ascii_code[1] = input_buffer[inbuff_offset + 1];
		ascii_code[2] = input_buffer[inbuff_offset + 2];
		inbuff_3xi = atoi(ascii_code);
		delibera_buffer[i] = (char)inbuff_3xi;
		inbuff_offset += 3;
		i++;
	}
	delibera_buffer[i] = '\0';

	if (! strcmp(delibera_buffer,"delabere" ))
		ok();
	else
		no();
	return 0;
}