/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcharbo <frcharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:15:51 by frcharbo          #+#    #+#             */
/*   Updated: 2024/11/24 02:05:00 by frcharbo         ###   ########.fr       */
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
                    // WARNING: Subroutine does not return
  exit(1);
}



void ok(void)

{
  puts("Good job.");
  return;
}

int main(void)
{
	size_t strlen_retval;
	int inbuff_3xi;
	bool offset_gt_ib;
	char ascii_code[4];
	char input_buffer [24];
	char starman [9];
	uint inbuff_offset;
	int i;
	printf("Please enter key: ");

	if (!scanf("%23s", input_buffer))
		no();

	if (input_buffer[1] != '2')
		no();

	if (input_buffer[0] != '4')
		no();

	fflush(stdin);
	memset(starman,0,9);
	starman[0] = '*';
	ascii_code[3] = 0;
	inbuff_offset = 2;
	i = 1;
	while( true )
	{
		strlen_retval = strlen(starman);
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
		starman[i] = (char)inbuff_3xi;
		inbuff_offset += 3;
		i++;
	}
	starman[i] = '\0';

	if (! strcmp(starman,"********" ))
		ok();
	else
		no();
	return 0;
}