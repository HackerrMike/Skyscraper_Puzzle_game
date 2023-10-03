/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guessing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:39:08 by frapp             #+#    #+#             */
/*   Updated: 2023/08/27 23:32:08 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	guessing(char guess[4][5], char pos_rs[24][5], int *indexes, char *inp);
int		increase_indexes(int *indexes);
int		do_checks(char guess[4][5], char *inp);

//copies one string into a diffrent memory location
void	ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
}

// fills the given array with all possible combinations
// of numbers that exist per row (without duplicate numbers)
void	generate_possible_rows(char possible_rows[24][5])
{
	ft_strcpy(possible_rows[0], "1234");
	ft_strcpy(possible_rows[1], "1243");
	ft_strcpy(possible_rows[2], "1324");
	ft_strcpy(possible_rows[3], "1342");
	ft_strcpy(possible_rows[4], "1423");
	ft_strcpy(possible_rows[5], "1432");
	ft_strcpy(possible_rows[6], "2134");
	ft_strcpy(possible_rows[7], "2143");
	ft_strcpy(possible_rows[8], "2314");
	ft_strcpy(possible_rows[9], "2341");
	ft_strcpy(possible_rows[10], "2413");
	ft_strcpy(possible_rows[11], "2431");
	ft_strcpy(possible_rows[12], "3124");
	ft_strcpy(possible_rows[13], "3142");
	ft_strcpy(possible_rows[14], "3214");
	ft_strcpy(possible_rows[15], "3241");
	ft_strcpy(possible_rows[16], "3412");
	ft_strcpy(possible_rows[17], "3421");
	ft_strcpy(possible_rows[18], "4123");
	ft_strcpy(possible_rows[19], "4132");
	ft_strcpy(possible_rows[20], "4213");
	ft_strcpy(possible_rows[21], "4231");
	ft_strcpy(possible_rows[22], "4312");
	ft_strcpy(possible_rows[23], "4321");
}

/*increments the array indexes used to pull possible rows.
if all combinations are tryed, it returns 0*/
int	increase_indexes(int *indexes)
{
	indexes[3]++;
	if (indexes[3] > 23)
	{
		indexes[3] = 0;
		indexes[2]++;
		if (indexes[2] > 23)
		{
			indexes[2] = 0;
			indexes[1]++;
			if (indexes[1] > 23)
			{
				indexes[1] = 0;
				indexes[0]++;
				if (indexes[0] > 23)
					return (0);
			}
		}
	}
	return (1);
}

/*this is the main loop that continuously updates the guessed board
 with possible row combinations and then tests them using the
two checks*/
void	guessing(char guess[4][5], char pos_rs[24][5], int *indexes, char *inp)
{
	int	check;

	while (1)
	{
		ft_strcpy(guess[0], pos_rs[indexes[0]]);
		ft_strcpy(guess[1], pos_rs[indexes[1]]);
		ft_strcpy(guess[2], pos_rs[indexes[2]]);
		ft_strcpy(guess[3], pos_rs[indexes[3]]);
		check = do_checks(guess, inp);
		if (check != 0)
			return ;
		check = increase_indexes(indexes);
		if (check == 0)
		{
			write(1, "Error\n", 6);
			return ;
		}
	}
}
