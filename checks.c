/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:27:19 by frapp             #+#    #+#             */
/*   Updated: 2023/08/27 22:51:40 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_column(char guess[4][5]);
int		check_input(char guess[4][5], char *input_str);

// checks if there duplicates in any column
// if a duplicate is found the do_checks() the next nunber is genrated
// if no duplicates are found the next ckeck will happen
int	check_column(char guess[4][5])
{
	int	row_nb;
	int	column_nb;
	int	i;

	row_nb = 0;
	while (row_nb < 3)
	{
		column_nb = 0;
		while (column_nb < 4)
		{
			i = 1;
			while (row_nb + i < 4)
			{
				if (guess[row_nb][column_nb] == guess[row_nb + i][column_nb])
					return (0);
				i++;
			}
			column_nb++;
		}
		row_nb++;
	}
	return (1);
}

// this function manges the two checks
// if a check fails the return value will be 0,
// which leads to more numbers beeing genrated
// if both checks pass any number != 0 is returned
// and the programm exists
int	do_checks(char guess[4][5], char *input_str)
{
	int	found;

	found = check_column(guess);
	if (found == 1)
		found = check_input(guess, input_str);
	return (found);
}
