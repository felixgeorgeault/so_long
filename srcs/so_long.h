/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:32:42 by fgeorgea          #+#    #+#             */
/*   Updated: 2023/02/09 14:52:05 by fgeorgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> // GET RID OF THAT SHIT !!!!!
# include "../includes/libft/libft.h"
# include "../includes/mlx/mlx.h"
# include <fcntl.h>

/*****************************************************************/
/*							ERROR MESSAGES					     */
/*****************************************************************/
# define GAME_TITLE "so_long"
# define ERR_BAD_ARG "Invalid number of arguments !\n"
# define ERR_PATH "The map does not exist ! Wrong file path\n"
# define ERR_BAD_EXT "Wrong extension file\n"
# define ERR_NBR_PLAYER1 "Only one player can be on the map\n"
# define ERR_NBR_PLAYER2 "Player is missing from the map\n"
# define ERR_NBR_EXIT1 "Only one exit allowed on the map\n"
# define ERR_NBR_EXIT2 "Map exit is missing\n"
# define ERR_MISSING_WALL "Walls missing from the map\n"
# define ERR_UKNOWN_CHAR_MAP "Unkown character in the map parsing\n"
# define ERR_INIT_IMG "Missing image\n"
# define ERR_PATH_FINDING "Unreachable exit or collectible\n"
# define ERR_MLX_INIT "mlx_init error\n"
# define ERR_MLX_WIN "mlx_new_window error\n"
# define ERR_COIN_INT_MAX "Your numbers of coins exceed the int max\n"
# define ERR_MEMORY "No enough memory\n"
# define ERR_EMPTY_MAP "The map is empty\n"

/*****************************************************************/
/*							STRUCTS								 */
/*****************************************************************/

typedef struct s_checkmap
{
	int	nbr_coin;
	int	nbr_player;
	int	nbr_exit;
	int	exit_pos_x;
	int	exit_pos_y;
	int	total_obj;
}	t_checkmap;

typedef struct s_map
{
	char	**map;
	char	**cp_map;
	int		nl;
	int		lenline;
}	t_map;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		coin_collected;
	int		move;
	char	char_staged;
}	t_player;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player_floor;
	void	*player_exit;
	void	*dclose;
	void	*dopen;
	void	*coin;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		*argv;
	int			w_height;
	int			w_width;
	int			argv_malloc;
	t_checkmap	check;
	t_map		map;
	t_player	player;
	t_img		img;
}	t_game;

// UTILS.C
void	ft_check_ber_ext(char *argv);
void    ft_error(int res, char *tab1, char **tab2, char *error);
void    ft_path_map(char *dir, char *argv, t_game *g);
void    ft_init_struct(t_game *g);
void	ft_init_lenline_nl(t_game *g);
#endif