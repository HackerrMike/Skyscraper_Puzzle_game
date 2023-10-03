/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:43:50 by frapp             #+#    #+#             */
/*   Updated: 2023/08/27 23:24:51 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	generate_possible_rows(char possible_rows[24][5]);
void	guessing(char guess[4][5], char pos_rs[24][5], int *indexes, char *inp);

/*initializes arrays, checks if the command line argument count
 is correct,sets initial values, generates possible rows,
  and then starts the guessing procedure*/
// guess structure: guess[row_index][column_index]
int	main(int ac, char *av[])
{
	char	possible_rows[24][5];
	char	guess[4][5];
	int		indexes[4];

	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	indexes[0] = 0;
	indexes[1] = 0;
	indexes[2] = 0;
	indexes[3] = 0;
	generate_possible_rows(possible_rows);
	guessing(guess, possible_rows, indexes, av[1]);
	return (0);
}
