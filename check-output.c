/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:48:38 by qdo               #+#    #+#             */
/*   Updated: 2023/08/27 23:33:10 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	count_col_up(char guess[4][5], char *comparison_string);
void	count_col_down(char guess[4][5], char *comparison_string);
void	count_row_left(char guess[4][5], char *comparison_string);
void	count_row_right(char guess[4][5], char *comparison_string);
void	ft_strcpy(char *dest, char *src);

//prints the guessed board (solution) with proper formatting
void	print_result_when_found(char guess[4][5])
{
	int	row_index;
	int	char_in_row_index;

	row_index = 0;
	while (row_index < 4)
	{
		char_in_row_index = 0;
		while (char_in_row_index < 4)
		{
			write(1, &(guess[row_index][char_in_row_index]), 1);
			if (char_in_row_index == 3)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			char_in_row_index++;
		}
		row_index++;
	}
}

//compares to string, returns 0 if they are the same, non zero otherwise
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*builds a string that describes the current guess visible
skyscrapers from all four sides; it then compares this build
string to the input provided to the program to determine if the guess
is a solution.*/
int	check_input(char guess[4][5], char *input_str)
{
	char	comparison_string[32];
	int		i;

	i = 0;
	while (i < 32)
	{
		comparison_string[i] = '\0';
		i++;
	}
	count_col_up(guess, comparison_string);
	count_col_down(guess, comparison_string);
	count_row_left(guess, comparison_string);
	count_row_right(guess, comparison_string);
	if (ft_strcmp(input_str, comparison_string) == 0)
	{
		print_result_when_found(guess);
		return (1);
	}
	else
		return (0);
}
