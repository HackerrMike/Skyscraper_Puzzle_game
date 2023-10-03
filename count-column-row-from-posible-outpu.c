/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_column_row_from_posible_outpu.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:47:32 by qdo               #+#    #+#             */
/*   Updated: 2023/08/27 23:35:01 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Appends a count (visible skyscrapers)
and a space to the cpare_str; used to build the string
for comparison against the input*/
void	append_count_to_string(char *dest, char count)
{
	int		dest_i;
	int		src_i;

	dest_i = 0;
	src_i = 0;
	while (dest[dest_i] != 0)
	{
		dest_i++;
	}
	dest[dest_i] = count;
	if (dest_i + 1 < 31)
	{
	dest[dest_i + 1] = ' ';
	dest[dest_i + 2] = 0;
	}
	else
	{
		dest[dest_i + 1] = '\0';
	}
}

// the final count (number of visable skyscapers from one point)
// corresponds to one digit of the input:
// starts at 1 because ther is at least 1 skyscarper visable
// every additonl visable one (bigger than the last biggest) increases the count
void	count_col_up(char guess[4][5], char *compare_str)
{
	int		row_index;
	int		column_index;
	char	highest_val_in_col;
	char	count;
	int		i;

	column_index = 0;
	while (column_index < 4)
	{
		count = '1';
		i = 1;
		row_index = 0;
		highest_val_in_col = guess[row_index][column_index];
		while (row_index + i <= 3)
		{
			if (highest_val_in_col < guess[row_index + i][column_index])
			{
				highest_val_in_col = guess[row_index + i][column_index];
				count++;
			}
			i++;
		}
		append_count_to_string(compare_str, count);
		column_index++;
	}
}

// the final count corresponds to one digit of the input:
// starts at 1 because ther is at least 1 skyscarper visable
// every additonl visable one (bigger than the last biggest) increases the count
void	count_col_down(char guess[4][5], char *compare_str)
{
	int		row_index;
	int		column_index;
	char	highest_val_in_col;
	char	count;
	int		i;

	column_index = 0;
	while (column_index < 4)
	{
		count = '1';
		i = 1;
		row_index = 3;
		highest_val_in_col = guess[row_index][column_index];
		while (row_index - i >= 0)
		{
			if (highest_val_in_col < guess[row_index - i][column_index])
			{
				highest_val_in_col = guess[row_index - i][column_index];
				count++;
			}
			i++;
		}
		append_count_to_string(compare_str, count);
		column_index++;
	}
}

// the final count corresponds to one digit of the input:
// starts at 1 because ther is at least 1 skyscarper visable
// every additonl visable one (bigger than the last biggest) increases the count
void	count_row_left(char guess[4][5], char *compare_str)
{
	int		column_index;
	int		row_index;
	char	higherst_val_in_row;
	char	count;
	int		i;

	row_index = 0;
	while (row_index < 4)
	{
		count = '1';
		i = 1;
		column_index = 0;
		higherst_val_in_row = guess[row_index][column_index];
		while (column_index + i <= 3)
		{
			if (higherst_val_in_row < guess[row_index][column_index + i])
			{
				higherst_val_in_row = guess[row_index][column_index + i];
				count++;
			}
			i++;
		}
		append_count_to_string(compare_str, count);
		row_index++;
	}
}

// the final count corresponds to one digit of the input:
// starts at 1 because ther is at least 1 skyscarper visable
// every additonl visable one (bigger than the last biggest) increases the count
void	count_row_right(char guess[4][5], char *compare_str)
{
	int		column_index;
	int		row_index;
	char	higherst_val_in_row;
	char	count;
	int		i;

	row_index = 0;
	while (row_index < 4)
	{
		i = 1;
		column_index = 3;
		higherst_val_in_row = guess[row_index][column_index];
		count = '1';
		while (column_index - i >= 0)
		{
			if (higherst_val_in_row < guess[row_index][column_index - i])
			{
				higherst_val_in_row = guess[row_index][column_index - i];
				count++;
			}
			i++;
		}
		append_count_to_string(compare_str, count);
		row_index++;
	}
}
