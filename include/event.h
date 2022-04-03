/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:16:06 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 16:11:01 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# define KEY_PRESS_EVENT		02
# define KEY_RELEASE_EVENT		03
# define DESTROY_NTFY_EVENT		33

# define KEY_A		0x61
# define KEY_S		0x73
# define KEY_D		0x64
# define KEY_W		0x77
# define KEY_ESC	0xff1b
# define KEY_LEFT	0xff51
# define KEY_RIGHT	0xff53

# include "cub3d.h"

int		set_exit_flag(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		game_close(t_game *game);

#endif
