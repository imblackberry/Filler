/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:30:00 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/20 19:30:01 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

int		show_score(WINDOW **score_w, char **game_arr)
{
	int o_result;
	int x_result;

	if (ft_strstr(game_arr[0], "== O fin") != 0)
	{
		init_pair(X_COLOR_PAIR, COLOR_BLACK, COLOR_YELLOW);
		init_pair(O_COLOR_PAIR, COLOR_BLACK, COLOR_RED);
		set_results(game_arr, &o_result, &x_result);
		mvwprintw(*score_w, 2, SCORE_X_SIZE / 2 - 2, "SCORE");
		wattron(*score_w, COLOR_PAIR(O_COLOR_PAIR));
		mvwprintw(*score_w, O_SCORE_LINE, 18, "O : %d", o_result);
		wattroff(*score_w, COLOR_PAIR(O_COLOR_PAIR));
		wattron(*score_w, COLOR_PAIR(X_COLOR_PAIR));
		mvwprintw(*score_w, X_SCORE_LINE, 18, "X : %d", x_result);
		wattroff(*score_w, COLOR_PAIR(X_COLOR_PAIR));
		show_who_is_who(score_w, o_result, x_result);
		wrefresh(*score_w);
		usleep(3000000);
		return (1);
	}
	return (0);
}

void	set_results(char **game_arr, int *o_result, int *x_result)
{
	*o_result = ft_atoi(game_arr[0] + 9);
	*x_result = ft_atoi(game_arr[1] + 9);
}

void	show_who_is_who(WINDOW **score_w, int o_result, int x_result)
{
	int loser_line;
	int winner_line;

	loser_line = 0;
	winner_line = 0;
	if (x_result == o_result)
	{
		mvwprintw(*score_w, O_SCORE_LINE, 2, "FUCKING");
		mvwprintw(*score_w, O_SCORE_LINE + 1, 3, "DRAW");
		mvwprintw(*score_w, O_SCORE_LINE + 2, 2, "HAHAHA");
		return ;
	}
	else if (x_result < o_result)
		winner_line = O_SCORE_LINE;
	else if (x_result > o_result)
		winner_line = X_SCORE_LINE;
	loser_line = (winner_line == X_SCORE_LINE) ? O_SCORE_LINE : X_SCORE_LINE;
	mvwprintw(*score_w, winner_line, 2, "FUCKING WINNER");
	mvwprintw(*score_w, loser_line, 2, "FUCKING LOSER");
}

void	sleep_and_refresh_w(WINDOW **window, int seconds)
{
	usleep(seconds);
	wrefresh(*window);
}
